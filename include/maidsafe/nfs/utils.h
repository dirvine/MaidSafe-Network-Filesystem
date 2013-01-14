/***************************************************************************************************
 *  Copyright 2012 MaidSafe.net limited                                                            *
 *                                                                                                 *
 *  The following source code is property of MaidSafe.net limited and is not meant for external    *
 *  use.  The use of this code is governed by the licence file licence.txt found in the root of    *
 *  this directory and also on www.maidsafe.net.                                                   *
 *                                                                                                 *
 *  You are not free to copy, amend or otherwise use this source code without the explicit         *
 *  written permission of the board of directors of MaidSafe.net.                                  *
 **************************************************************************************************/

#ifndef MAIDSAFE_NFS_UTILS_H_
#define MAIDSAFE_NFS_UTILS_H_

#include <exception>
#include <future>
#include <string>
#include <vector>

#include "maidsafe/common/error.h"
#include "maidsafe/common/log.h"
#include "maidsafe/common/node_id.h"
#include "maidsafe/common/rsa.h"
#include "maidsafe/common/utils.h"
#include "maidsafe/common/types.h"

#include "maidsafe/nfs/message.h"
#include "maidsafe/nfs/post_message.h"
#include "maidsafe/nfs/return_code.h"
#include "maidsafe/nfs/utils.h"
#include "maidsafe/nfs/types.h"


namespace maidsafe {

namespace nfs {

template<typename Data>
bool IsCacheable() {
  return is_long_term_cacheable<Data>::value || is_short_term_cacheable<Data>::value;
}

template<typename Data>
Data ValidateAndParse(const Message& message) {
  return Data(typename Data::name_type(message.name()),
              typename Data::serialised_type(message.content()));
}

template<typename Data>
void HandleGetFutures(std::shared_ptr<std::promise<Data>> promise,
                      std::shared_ptr<std::vector<std::future<std::string>>> routing_futures) {
  auto functor([=] {
      while (!routing_futures->empty()) {
        auto itr(routing_futures->begin());
        while (itr != routing_futures->end()) {
          if (IsReady(*itr)) {
            try {
              std::string serialised_message((*itr).get());
              // Need '((' when constructing Message to avoid most vexing parse.
              Message message((Message::serialised_type(NonEmptyString(serialised_message))));
              Data data(ValidateAndParse<Data>(message));
              promise->set_value(std::move(data));
              return;
            }
            catch(const std::system_error& error) {
              LOG(kError) << error.code() << " - " << error.what();
              itr = routing_futures->erase(itr);
            }
          } else {
            ++itr;
          }
        }
        std::this_thread::yield();
      }
      promise->set_exception(std::make_exception_ptr(MakeError(NfsErrors::failed_to_get_data)));
  });
  std::thread worker(functor);
  worker.detach();
}

template<typename Data>
void HandlePutResponse(OnError on_error_functor,
                       Message original_message,
                       const std::vector<std::string>& serialised_messages) {
  if (serialised_messages.empty()) {
    LOG(kError) << "No responses received for Put " << original_message.data_type()
                << "  " << HexSubstr(original_message.name());
    on_error_functor(std::move(original_message));
  }

  // TODO(Fraser#5#): 2012-12-21 - Confirm this is OK as a means of deciding overall success
  int success_count(0), failure_count(0);
  for (auto& serialised_message : serialised_messages) {
    try {
      // Need '((' when constructing ReturnCode to avoid most vexing parse.
      ReturnCode return_code((ReturnCode::serialised_type(NonEmptyString(serialised_message))));
      if (static_cast<CommonErrors>(return_code.value()) == CommonErrors::success) {
        ++success_count;
      } else {
        LOG(kWarning) << "Received an error " << return_code.value() << " for Put "
                      << original_message.data_type() << " "
                      << HexSubstr(original_message.name());
        ++failure_count;
      }
    }
    catch(const std::exception& e) {
      ++failure_count;
      LOG(kError) <<  e.what();
    }
  }

  if (success_count == 0) {
    LOG(kError) << "No successful responses received for Put " << original_message.data_type()
                << "  " << HexSubstr(original_message.name()) << "  received "
                << failure_count << " failures.";
    on_error_functor(std::move(original_message));
  }
  LOG(kVerbose) << "Overall success for Put " << original_message.data_type()
                << "  " << HexSubstr(original_message.name()) << "  received "
                << success_count << " successes and " << failure_count << " failures.";
}

template<typename Data>
void HandleDeleteResponse(OnError on_error_functor,
                          Message original_message,
                          const std::vector<std::string>& serialised_messages) {
  if (serialised_messages.empty()) {
    LOG(kError) << "No responses received for Delete " << original_message.data_type()
                << "  " << DebugId(original_message.name());
    on_error_functor(std::move(original_message));
  }

  // TODO(Fraser#5#): 2012-12-21 - Confirm this is OK as a means of deciding overall success
  int success_count(0), failure_count(0);
  for (auto& serialised_message : serialised_messages) {
    try {
      // Need '((' when constructing ReturnCode to avoid most vexing parse.
      ReturnCode return_code((ReturnCode::serialised_type(NonEmptyString(serialised_message))));
      if (static_cast<CommonErrors>(return_code.value()) == CommonErrors::success) {
        ++success_count;
      } else {
        LOG(kWarning) << "Received an error " << return_code.value() << " for Delete "
                      << original_message.data_type() << " "
                      << DebugId(original_message.name());
        ++failure_count;
      }
    }
    catch(const std::exception& e) {
      ++failure_count;
      LOG(kError) <<  e.what();
    }
  }

  if (success_count == 0) {
    LOG(kError) << "No successful responses received for Delete " << original_message.data_type()
                << "  " << DebugId(original_message.name()) << "  received "
                << failure_count << " failures.";
    on_error_functor(std::move(original_message));
  }
  LOG(kVerbose) << "Overall success for Delete " << original_message.data_type()
                << "  " << DebugId(original_message.name()) << "  received "
                << success_count << " successes and " << failure_count << " failures.";
}

void HandlePostResponse(OnPostError /*on_error_functor*/,
                        PostMessage /*original_message*/,
                        const std::vector<std::string>& /*serialised_messages*/);

}  // namespace nfs

}  // namespace maidsafe

#endif  // MAIDSAFE_NFS_UTILS_H_
