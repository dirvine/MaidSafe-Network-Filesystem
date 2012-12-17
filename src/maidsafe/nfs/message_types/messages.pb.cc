// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "maidsafe/nfs/message_types/messages.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
// @@protoc_insertion_point(includes)

namespace maidsafe {
namespace nfs {
namespace proto {

void protobuf_ShutdownFile_maidsafe_2fnfs_2fmessage_5ftypes_2fmessages_2eproto() {
  delete Nfs::default_instance_;
}

void protobuf_AddDesc_maidsafe_2fnfs_2fmessage_5ftypes_2fmessages_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  Nfs::default_instance_ = new Nfs();
  Nfs::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_maidsafe_2fnfs_2fmessage_5ftypes_2fmessages_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_maidsafe_2fnfs_2fmessage_5ftypes_2fmessages_2eproto {
  StaticDescriptorInitializer_maidsafe_2fnfs_2fmessage_5ftypes_2fmessages_2eproto() {
    protobuf_AddDesc_maidsafe_2fnfs_2fmessage_5ftypes_2fmessages_2eproto();
  }
} static_descriptor_initializer_maidsafe_2fnfs_2fmessage_5ftypes_2fmessages_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int Nfs::kActionTypeFieldNumber;
const int Nfs::kPersonaTypeFieldNumber;
const int Nfs::kDataTypeFieldNumber;
const int Nfs::kDestinationFieldNumber;
const int Nfs::kSourceFieldNumber;
const int Nfs::kContentFieldNumber;
const int Nfs::kSignatureFieldNumber;
#endif  // !_MSC_VER

Nfs::Nfs()
  : ::google::protobuf::MessageLite() {
  SharedCtor();
}

void Nfs::InitAsDefaultInstance() {
}

Nfs::Nfs(const Nfs& from)
  : ::google::protobuf::MessageLite() {
  SharedCtor();
  MergeFrom(from);
}

void Nfs::SharedCtor() {
  _cached_size_ = 0;
  action_type_ = 0;
  persona_type_ = 0;
  data_type_ = 0;
  destination_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  source_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  content_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  signature_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Nfs::~Nfs() {
  SharedDtor();
}

void Nfs::SharedDtor() {
  if (destination_ != &::google::protobuf::internal::kEmptyString) {
    delete destination_;
  }
  if (source_ != &::google::protobuf::internal::kEmptyString) {
    delete source_;
  }
  if (content_ != &::google::protobuf::internal::kEmptyString) {
    delete content_;
  }
  if (signature_ != &::google::protobuf::internal::kEmptyString) {
    delete signature_;
  }
  if (this != default_instance_) {
  }
}

void Nfs::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const Nfs& Nfs::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_maidsafe_2fnfs_2fmessage_5ftypes_2fmessages_2eproto();  return *default_instance_;
}

Nfs* Nfs::default_instance_ = NULL;

Nfs* Nfs::New() const {
  return new Nfs;
}

void Nfs::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    action_type_ = 0;
    persona_type_ = 0;
    data_type_ = 0;
    if (has_destination()) {
      if (destination_ != &::google::protobuf::internal::kEmptyString) {
        destination_->clear();
      }
    }
    if (has_source()) {
      if (source_ != &::google::protobuf::internal::kEmptyString) {
        source_->clear();
      }
    }
    if (has_content()) {
      if (content_ != &::google::protobuf::internal::kEmptyString) {
        content_->clear();
      }
    }
    if (has_signature()) {
      if (signature_ != &::google::protobuf::internal::kEmptyString) {
        signature_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

bool Nfs::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 action_type = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &action_type_)));
          set_has_action_type();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_persona_type;
        break;
      }
      
      // required int32 persona_type = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_persona_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &persona_type_)));
          set_has_persona_type();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_data_type;
        break;
      }
      
      // required int32 data_type = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_data_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &data_type_)));
          set_has_data_type();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_destination;
        break;
      }
      
      // required bytes destination = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_destination:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_destination()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(42)) goto parse_source;
        break;
      }
      
      // required bytes source = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_source:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_source()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(50)) goto parse_content;
        break;
      }
      
      // required bytes content = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_content:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_content()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(58)) goto parse_signature;
        break;
      }
      
      // optional bytes signature = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_signature:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_signature()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Nfs::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 action_type = 1;
  if (has_action_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->action_type(), output);
  }
  
  // required int32 persona_type = 2;
  if (has_persona_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->persona_type(), output);
  }
  
  // required int32 data_type = 3;
  if (has_data_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->data_type(), output);
  }
  
  // required bytes destination = 4;
  if (has_destination()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      4, this->destination(), output);
  }
  
  // required bytes source = 5;
  if (has_source()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      5, this->source(), output);
  }
  
  // required bytes content = 6;
  if (has_content()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      6, this->content(), output);
  }
  
  // optional bytes signature = 7;
  if (has_signature()) {
    ::google::protobuf::internal::WireFormatLite::WriteBytes(
      7, this->signature(), output);
  }
  
}

int Nfs::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 action_type = 1;
    if (has_action_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->action_type());
    }
    
    // required int32 persona_type = 2;
    if (has_persona_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->persona_type());
    }
    
    // required int32 data_type = 3;
    if (has_data_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->data_type());
    }
    
    // required bytes destination = 4;
    if (has_destination()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->destination());
    }
    
    // required bytes source = 5;
    if (has_source()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->source());
    }
    
    // required bytes content = 6;
    if (has_content()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->content());
    }
    
    // optional bytes signature = 7;
    if (has_signature()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::BytesSize(
          this->signature());
    }
    
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Nfs::CheckTypeAndMergeFrom(
    const ::google::protobuf::MessageLite& from) {
  MergeFrom(*::google::protobuf::down_cast<const Nfs*>(&from));
}

void Nfs::MergeFrom(const Nfs& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_action_type()) {
      set_action_type(from.action_type());
    }
    if (from.has_persona_type()) {
      set_persona_type(from.persona_type());
    }
    if (from.has_data_type()) {
      set_data_type(from.data_type());
    }
    if (from.has_destination()) {
      set_destination(from.destination());
    }
    if (from.has_source()) {
      set_source(from.source());
    }
    if (from.has_content()) {
      set_content(from.content());
    }
    if (from.has_signature()) {
      set_signature(from.signature());
    }
  }
}

void Nfs::CopyFrom(const Nfs& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Nfs::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000003f) != 0x0000003f) return false;
  
  return true;
}

void Nfs::Swap(Nfs* other) {
  if (other != this) {
    std::swap(action_type_, other->action_type_);
    std::swap(persona_type_, other->persona_type_);
    std::swap(data_type_, other->data_type_);
    std::swap(destination_, other->destination_);
    std::swap(source_, other->source_);
    std::swap(content_, other->content_);
    std::swap(signature_, other->signature_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::std::string Nfs::GetTypeName() const {
  return "maidsafe.nfs.proto.Nfs";
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace nfs
}  // namespace maidsafe

// @@protoc_insertion_point(global_scope)
