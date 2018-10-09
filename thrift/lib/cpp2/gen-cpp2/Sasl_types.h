/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/GeneratedHeaderHelper.h>
#include <thrift/lib/cpp2/Thrift.h>
#include <thrift/lib/cpp2/protocol/Protocol.h>


// BEGIN declare_enums

// END declare_enums
// BEGIN struct_indirection

// END struct_indirection
// BEGIN forward_declare
namespace apache { namespace thrift { namespace sasl {
class SaslOutcome;
class SaslRequest;
class SaslReply;
class SaslStart;
}}} // apache::thrift::sasl
// END forward_declare
// BEGIN typedefs

// END typedefs
// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace apache { namespace thrift { namespace sasl {
class SaslOutcome final : private apache::thrift::detail::st::ComparisonOperators<SaslOutcome> {
 public:

  SaslOutcome() :
      success(0) {}
  // FragileConstructor for use in initialization lists only.
  SaslOutcome(apache::thrift::FragileConstructor, bool success__arg, std::string additional_data__arg);
  template <typename T__ThriftWrappedArgument__Ctor, typename... Args__ThriftWrappedArgument__Ctor>
  SaslOutcome(::apache::thrift::detail::argument_wrapper<1, T__ThriftWrappedArgument__Ctor> arg, Args__ThriftWrappedArgument__Ctor&&... args):
    SaslOutcome(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    success = arg.move();
    __isset.success = true;
  }
  template <typename T__ThriftWrappedArgument__Ctor, typename... Args__ThriftWrappedArgument__Ctor>
  SaslOutcome(::apache::thrift::detail::argument_wrapper<2, T__ThriftWrappedArgument__Ctor> arg, Args__ThriftWrappedArgument__Ctor&&... args):
    SaslOutcome(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    additional_data = arg.move();
    __isset.additional_data = true;
  }

  SaslOutcome(SaslOutcome&&) = default;

  SaslOutcome(const SaslOutcome&) = default;

  SaslOutcome& operator=(SaslOutcome&&) = default;

  SaslOutcome& operator=(const SaslOutcome&) = default;
  void __clear();
  bool success;
  std::string additional_data;

  struct __isset {
    bool success;
    bool additional_data;
  } __isset = {};
  bool operator==(const SaslOutcome& rhs) const;
  bool operator < (const SaslOutcome& rhs) const;

  bool get_success() const {
    return success;
  }

  bool& set_success(bool success_) {
    success = success_;
    __isset.success = true;
    return success;
  }

  const std::string* get_additional_data() const& {
    return __isset.additional_data ? std::addressof(additional_data) : nullptr;
  }

  std::string* get_additional_data() & {
    return __isset.additional_data ? std::addressof(additional_data) : nullptr;
  }
  std::string* get_additional_data() && = delete;

  template <typename T_SaslOutcome_additional_data_struct_setter>
  std::string& set_additional_data(T_SaslOutcome_additional_data_struct_setter&& additional_data_) {
    additional_data = std::forward<T_SaslOutcome_additional_data_struct_setter>(additional_data_);
    __isset.additional_data = true;
    return additional_data;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  static void translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype);
};

void swap(SaslOutcome& a, SaslOutcome& b);
extern template uint32_t SaslOutcome::read<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t SaslOutcome::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t SaslOutcome::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t SaslOutcome::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t SaslOutcome::read<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t SaslOutcome::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t SaslOutcome::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t SaslOutcome::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}} // apache::thrift::sasl
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::apache::thrift::sasl::SaslOutcome>::clear( ::apache::thrift::sasl::SaslOutcome* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::apache::thrift::sasl::SaslOutcome>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslOutcome>::write(Protocol* proto,  ::apache::thrift::sasl::SaslOutcome const* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslOutcome>::read(Protocol* proto,  ::apache::thrift::sasl::SaslOutcome* obj) {
  return obj->read(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslOutcome>::serializedSize(Protocol const* proto,  ::apache::thrift::sasl::SaslOutcome const* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslOutcome>::serializedSizeZC(Protocol const* proto,  ::apache::thrift::sasl::SaslOutcome const* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
namespace apache { namespace thrift { namespace sasl {
class SaslRequest final : private apache::thrift::detail::st::ComparisonOperators<SaslRequest> {
 public:

  SaslRequest() :
      abort(0) {}
  // FragileConstructor for use in initialization lists only.
  SaslRequest(apache::thrift::FragileConstructor, std::string response__arg, bool abort__arg);
  template <typename T__ThriftWrappedArgument__Ctor, typename... Args__ThriftWrappedArgument__Ctor>
  SaslRequest(::apache::thrift::detail::argument_wrapper<1, T__ThriftWrappedArgument__Ctor> arg, Args__ThriftWrappedArgument__Ctor&&... args):
    SaslRequest(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    response = arg.move();
    __isset.response = true;
  }
  template <typename T__ThriftWrappedArgument__Ctor, typename... Args__ThriftWrappedArgument__Ctor>
  SaslRequest(::apache::thrift::detail::argument_wrapper<2, T__ThriftWrappedArgument__Ctor> arg, Args__ThriftWrappedArgument__Ctor&&... args):
    SaslRequest(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    abort = arg.move();
    __isset.abort = true;
  }

  SaslRequest(SaslRequest&&) = default;

  SaslRequest(const SaslRequest&) = default;

  SaslRequest& operator=(SaslRequest&&) = default;

  SaslRequest& operator=(const SaslRequest&) = default;
  void __clear();
  std::string response;
  bool abort;

  struct __isset {
    bool response;
    bool abort;
  } __isset = {};
  bool operator==(const SaslRequest& rhs) const;
  bool operator < (const SaslRequest& rhs) const;

  const std::string* get_response() const& {
    return __isset.response ? std::addressof(response) : nullptr;
  }

  std::string* get_response() & {
    return __isset.response ? std::addressof(response) : nullptr;
  }
  std::string* get_response() && = delete;

  template <typename T_SaslRequest_response_struct_setter>
  std::string& set_response(T_SaslRequest_response_struct_setter&& response_) {
    response = std::forward<T_SaslRequest_response_struct_setter>(response_);
    __isset.response = true;
    return response;
  }

  const bool* get_abort() const& {
    return __isset.abort ? std::addressof(abort) : nullptr;
  }

  bool* get_abort() & {
    return __isset.abort ? std::addressof(abort) : nullptr;
  }
  bool* get_abort() && = delete;

  bool& set_abort(bool abort_) {
    abort = abort_;
    __isset.abort = true;
    return abort;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  static void translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype);
};

void swap(SaslRequest& a, SaslRequest& b);
extern template uint32_t SaslRequest::read<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t SaslRequest::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t SaslRequest::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t SaslRequest::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t SaslRequest::read<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t SaslRequest::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t SaslRequest::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t SaslRequest::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}} // apache::thrift::sasl
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::apache::thrift::sasl::SaslRequest>::clear( ::apache::thrift::sasl::SaslRequest* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::apache::thrift::sasl::SaslRequest>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslRequest>::write(Protocol* proto,  ::apache::thrift::sasl::SaslRequest const* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslRequest>::read(Protocol* proto,  ::apache::thrift::sasl::SaslRequest* obj) {
  return obj->read(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslRequest>::serializedSize(Protocol const* proto,  ::apache::thrift::sasl::SaslRequest const* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslRequest>::serializedSizeZC(Protocol const* proto,  ::apache::thrift::sasl::SaslRequest const* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
namespace apache { namespace thrift { namespace sasl {
class SaslReply final : private apache::thrift::detail::st::ComparisonOperators<SaslReply> {
 public:

  SaslReply() {}
  // FragileConstructor for use in initialization lists only.
  SaslReply(apache::thrift::FragileConstructor, std::string challenge__arg,  ::apache::thrift::sasl::SaslOutcome outcome__arg, std::string mechanism__arg);
  template <typename T__ThriftWrappedArgument__Ctor, typename... Args__ThriftWrappedArgument__Ctor>
  SaslReply(::apache::thrift::detail::argument_wrapper<1, T__ThriftWrappedArgument__Ctor> arg, Args__ThriftWrappedArgument__Ctor&&... args):
    SaslReply(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    challenge = arg.move();
    __isset.challenge = true;
  }
  template <typename T__ThriftWrappedArgument__Ctor, typename... Args__ThriftWrappedArgument__Ctor>
  SaslReply(::apache::thrift::detail::argument_wrapper<2, T__ThriftWrappedArgument__Ctor> arg, Args__ThriftWrappedArgument__Ctor&&... args):
    SaslReply(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    outcome = arg.move();
    __isset.outcome = true;
  }
  template <typename T__ThriftWrappedArgument__Ctor, typename... Args__ThriftWrappedArgument__Ctor>
  SaslReply(::apache::thrift::detail::argument_wrapper<3, T__ThriftWrappedArgument__Ctor> arg, Args__ThriftWrappedArgument__Ctor&&... args):
    SaslReply(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    mechanism = arg.move();
    __isset.mechanism = true;
  }

  SaslReply(SaslReply&&) = default;

  SaslReply(const SaslReply&) = default;

  SaslReply& operator=(SaslReply&&) = default;

  SaslReply& operator=(const SaslReply&) = default;
  void __clear();
  std::string challenge;
   ::apache::thrift::sasl::SaslOutcome outcome;
  std::string mechanism;

  struct __isset {
    bool challenge;
    bool outcome;
    bool mechanism;
  } __isset = {};
  bool operator==(const SaslReply& rhs) const;
  bool operator < (const SaslReply& rhs) const;

  const std::string* get_challenge() const& {
    return __isset.challenge ? std::addressof(challenge) : nullptr;
  }

  std::string* get_challenge() & {
    return __isset.challenge ? std::addressof(challenge) : nullptr;
  }
  std::string* get_challenge() && = delete;

  template <typename T_SaslReply_challenge_struct_setter>
  std::string& set_challenge(T_SaslReply_challenge_struct_setter&& challenge_) {
    challenge = std::forward<T_SaslReply_challenge_struct_setter>(challenge_);
    __isset.challenge = true;
    return challenge;
  }
  const  ::apache::thrift::sasl::SaslOutcome* get_outcome() const&;
   ::apache::thrift::sasl::SaslOutcome* get_outcome() &;
   ::apache::thrift::sasl::SaslOutcome* get_outcome() && = delete;

  template <typename T_SaslReply_outcome_struct_setter>
   ::apache::thrift::sasl::SaslOutcome& set_outcome(T_SaslReply_outcome_struct_setter&& outcome_) {
    outcome = std::forward<T_SaslReply_outcome_struct_setter>(outcome_);
    __isset.outcome = true;
    return outcome;
  }

  const std::string* get_mechanism() const& {
    return __isset.mechanism ? std::addressof(mechanism) : nullptr;
  }

  std::string* get_mechanism() & {
    return __isset.mechanism ? std::addressof(mechanism) : nullptr;
  }
  std::string* get_mechanism() && = delete;

  template <typename T_SaslReply_mechanism_struct_setter>
  std::string& set_mechanism(T_SaslReply_mechanism_struct_setter&& mechanism_) {
    mechanism = std::forward<T_SaslReply_mechanism_struct_setter>(mechanism_);
    __isset.mechanism = true;
    return mechanism;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  static void translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype);
};

void swap(SaslReply& a, SaslReply& b);
extern template uint32_t SaslReply::read<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t SaslReply::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t SaslReply::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t SaslReply::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t SaslReply::read<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t SaslReply::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t SaslReply::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t SaslReply::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}} // apache::thrift::sasl
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::apache::thrift::sasl::SaslReply>::clear( ::apache::thrift::sasl::SaslReply* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::apache::thrift::sasl::SaslReply>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslReply>::write(Protocol* proto,  ::apache::thrift::sasl::SaslReply const* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslReply>::read(Protocol* proto,  ::apache::thrift::sasl::SaslReply* obj) {
  return obj->read(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslReply>::serializedSize(Protocol const* proto,  ::apache::thrift::sasl::SaslReply const* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslReply>::serializedSizeZC(Protocol const* proto,  ::apache::thrift::sasl::SaslReply const* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
namespace apache { namespace thrift { namespace sasl {
class SaslStart final : private apache::thrift::detail::st::ComparisonOperators<SaslStart> {
 public:

  SaslStart() {}
  // FragileConstructor for use in initialization lists only.
  SaslStart(apache::thrift::FragileConstructor, std::string mechanism__arg,  ::apache::thrift::sasl::SaslRequest request__arg, std::vector<std::string> mechanisms__arg);
  template <typename T__ThriftWrappedArgument__Ctor, typename... Args__ThriftWrappedArgument__Ctor>
  SaslStart(::apache::thrift::detail::argument_wrapper<1, T__ThriftWrappedArgument__Ctor> arg, Args__ThriftWrappedArgument__Ctor&&... args):
    SaslStart(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    mechanism = arg.move();
    __isset.mechanism = true;
  }
  template <typename T__ThriftWrappedArgument__Ctor, typename... Args__ThriftWrappedArgument__Ctor>
  SaslStart(::apache::thrift::detail::argument_wrapper<2, T__ThriftWrappedArgument__Ctor> arg, Args__ThriftWrappedArgument__Ctor&&... args):
    SaslStart(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    request = arg.move();
    __isset.request = true;
  }
  template <typename T__ThriftWrappedArgument__Ctor, typename... Args__ThriftWrappedArgument__Ctor>
  SaslStart(::apache::thrift::detail::argument_wrapper<3, T__ThriftWrappedArgument__Ctor> arg, Args__ThriftWrappedArgument__Ctor&&... args):
    SaslStart(std::forward<Args__ThriftWrappedArgument__Ctor>(args)...)
  {
    mechanisms = arg.move();
    __isset.mechanisms = true;
  }

  SaslStart(SaslStart&&) = default;

  SaslStart(const SaslStart&) = default;

  SaslStart& operator=(SaslStart&&) = default;

  SaslStart& operator=(const SaslStart&) = default;
  void __clear();
  std::string mechanism;
   ::apache::thrift::sasl::SaslRequest request;
  std::vector<std::string> mechanisms;

  struct __isset {
    bool mechanism;
    bool request;
    bool mechanisms;
  } __isset = {};
  bool operator==(const SaslStart& rhs) const;
  bool operator < (const SaslStart& rhs) const;

  const std::string& get_mechanism() const& {
    return mechanism;
  }

  std::string get_mechanism() && {
    return std::move(mechanism);
  }

  template <typename T_SaslStart_mechanism_struct_setter>
  std::string& set_mechanism(T_SaslStart_mechanism_struct_setter&& mechanism_) {
    mechanism = std::forward<T_SaslStart_mechanism_struct_setter>(mechanism_);
    __isset.mechanism = true;
    return mechanism;
  }
  const  ::apache::thrift::sasl::SaslRequest* get_request() const&;
   ::apache::thrift::sasl::SaslRequest* get_request() &;
   ::apache::thrift::sasl::SaslRequest* get_request() && = delete;

  template <typename T_SaslStart_request_struct_setter>
   ::apache::thrift::sasl::SaslRequest& set_request(T_SaslStart_request_struct_setter&& request_) {
    request = std::forward<T_SaslStart_request_struct_setter>(request_);
    __isset.request = true;
    return request;
  }
  const std::vector<std::string>* get_mechanisms() const&;
  std::vector<std::string>* get_mechanisms() &;
  std::vector<std::string>* get_mechanisms() && = delete;

  template <typename T_SaslStart_mechanisms_struct_setter>
  std::vector<std::string>& set_mechanisms(T_SaslStart_mechanisms_struct_setter&& mechanisms_) {
    mechanisms = std::forward<T_SaslStart_mechanisms_struct_setter>(mechanisms_);
    __isset.mechanisms = true;
    return mechanisms;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  static void translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype);
};

void swap(SaslStart& a, SaslStart& b);
extern template uint32_t SaslStart::read<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t SaslStart::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t SaslStart::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t SaslStart::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t SaslStart::read<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t SaslStart::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t SaslStart::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t SaslStart::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}} // apache::thrift::sasl
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::apache::thrift::sasl::SaslStart>::clear( ::apache::thrift::sasl::SaslStart* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::apache::thrift::sasl::SaslStart>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslStart>::write(Protocol* proto,  ::apache::thrift::sasl::SaslStart const* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslStart>::read(Protocol* proto,  ::apache::thrift::sasl::SaslStart* obj) {
  return obj->read(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslStart>::serializedSize(Protocol const* proto,  ::apache::thrift::sasl::SaslStart const* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::apache::thrift::sasl::SaslStart>::serializedSizeZC(Protocol const* proto,  ::apache::thrift::sasl::SaslStart const* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift