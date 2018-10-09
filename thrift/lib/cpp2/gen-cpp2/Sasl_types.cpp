/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/lib/cpp2/gen-cpp2/Sasl_types.h"
#include "thrift/lib/cpp2/gen-cpp2/Sasl_types.tcc"

#include <algorithm>
#include <folly/Indestructible.h>

#include "thrift/lib/cpp2/gen-cpp2/Sasl_data.h"

namespace apache { namespace thrift { namespace sasl {

SaslOutcome::SaslOutcome(apache::thrift::FragileConstructor, bool success__arg, std::string additional_data__arg) :
    success(std::move(success__arg)),
    additional_data(std::move(additional_data__arg)) {
  __isset.success = true;
  __isset.additional_data = true;
}

void SaslOutcome::__clear() {
  // clear all fields
  success = 0;
  additional_data = apache::thrift::StringTraits< std::string>::fromStringLiteral("");
  __isset = {};
}

bool SaslOutcome::operator==(const SaslOutcome& rhs) const {
  if (!((success == rhs.success))) {
    return false;
  }
  if (__isset.additional_data != rhs.__isset.additional_data) {
    return false;
  }
  else if (__isset.additional_data && !((additional_data == rhs.additional_data))) {
    return false;
  }
  return true;
}

void SaslOutcome::translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "success") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_BOOL;
  }
  else if (_fname == "additional_data") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_STRING;
  }
}

void swap(SaslOutcome& a, SaslOutcome& b) {
  using ::std::swap;
  swap(a.success, b.success);
  swap(a.additional_data, b.additional_data);
  swap(a.__isset, b.__isset);
}

template uint32_t SaslOutcome::read<>(apache::thrift::BinaryProtocolReader*);
template uint32_t SaslOutcome::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t SaslOutcome::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t SaslOutcome::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t SaslOutcome::read<>(apache::thrift::CompactProtocolReader*);
template uint32_t SaslOutcome::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t SaslOutcome::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t SaslOutcome::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}} // apache::thrift::sasl
namespace apache { namespace thrift { namespace sasl {

SaslRequest::SaslRequest(apache::thrift::FragileConstructor, std::string response__arg, bool abort__arg) :
    response(std::move(response__arg)),
    abort(std::move(abort__arg)) {
  __isset.response = true;
  __isset.abort = true;
}

void SaslRequest::__clear() {
  // clear all fields
  response = apache::thrift::StringTraits< std::string>::fromStringLiteral("");
  abort = 0;
  __isset = {};
}

bool SaslRequest::operator==(const SaslRequest& rhs) const {
  if (__isset.response != rhs.__isset.response) {
    return false;
  }
  else if (__isset.response && !((response == rhs.response))) {
    return false;
  }
  if (__isset.abort != rhs.__isset.abort) {
    return false;
  }
  else if (__isset.abort && !((abort == rhs.abort))) {
    return false;
  }
  return true;
}

void SaslRequest::translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "response") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "abort") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_BOOL;
  }
}

void swap(SaslRequest& a, SaslRequest& b) {
  using ::std::swap;
  swap(a.response, b.response);
  swap(a.abort, b.abort);
  swap(a.__isset, b.__isset);
}

template uint32_t SaslRequest::read<>(apache::thrift::BinaryProtocolReader*);
template uint32_t SaslRequest::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t SaslRequest::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t SaslRequest::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t SaslRequest::read<>(apache::thrift::CompactProtocolReader*);
template uint32_t SaslRequest::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t SaslRequest::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t SaslRequest::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}} // apache::thrift::sasl
namespace apache { namespace thrift { namespace sasl {

SaslReply::SaslReply(apache::thrift::FragileConstructor, std::string challenge__arg,  ::apache::thrift::sasl::SaslOutcome outcome__arg, std::string mechanism__arg) :
    challenge(std::move(challenge__arg)),
    outcome(std::move(outcome__arg)),
    mechanism(std::move(mechanism__arg)) {
  __isset.challenge = true;
  __isset.outcome = true;
  __isset.mechanism = true;
}

void SaslReply::__clear() {
  // clear all fields
  challenge = apache::thrift::StringTraits< std::string>::fromStringLiteral("");
  ::apache::thrift::Cpp2Ops<  ::apache::thrift::sasl::SaslOutcome>::clear(&outcome);
  mechanism = apache::thrift::StringTraits< std::string>::fromStringLiteral("");
  __isset = {};
}

bool SaslReply::operator==(const SaslReply& rhs) const {
  if (__isset.challenge != rhs.__isset.challenge) {
    return false;
  }
  else if (__isset.challenge && !((challenge == rhs.challenge))) {
    return false;
  }
  if (__isset.outcome != rhs.__isset.outcome) {
    return false;
  }
  else if (__isset.outcome && !((outcome == rhs.outcome))) {
    return false;
  }
  if (__isset.mechanism != rhs.__isset.mechanism) {
    return false;
  }
  else if (__isset.mechanism && !((mechanism == rhs.mechanism))) {
    return false;
  }
  return true;
}

const  ::apache::thrift::sasl::SaslOutcome* SaslReply::get_outcome() const& {
  return __isset.outcome ? std::addressof(outcome) : nullptr;
}

 ::apache::thrift::sasl::SaslOutcome* SaslReply::get_outcome() & {
  return __isset.outcome ? std::addressof(outcome) : nullptr;
}

void SaslReply::translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "challenge") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "outcome") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_STRUCT;
  }
  else if (_fname == "mechanism") {
    fid = 3;
    _ftype = apache::thrift::protocol::T_STRING;
  }
}

void swap(SaslReply& a, SaslReply& b) {
  using ::std::swap;
  swap(a.challenge, b.challenge);
  swap(a.outcome, b.outcome);
  swap(a.mechanism, b.mechanism);
  swap(a.__isset, b.__isset);
}

template uint32_t SaslReply::read<>(apache::thrift::BinaryProtocolReader*);
template uint32_t SaslReply::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t SaslReply::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t SaslReply::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t SaslReply::read<>(apache::thrift::CompactProtocolReader*);
template uint32_t SaslReply::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t SaslReply::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t SaslReply::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}} // apache::thrift::sasl
namespace apache { namespace thrift { namespace sasl {

SaslStart::SaslStart(apache::thrift::FragileConstructor, std::string mechanism__arg,  ::apache::thrift::sasl::SaslRequest request__arg, std::vector<std::string> mechanisms__arg) :
    mechanism(std::move(mechanism__arg)),
    request(std::move(request__arg)),
    mechanisms(std::move(mechanisms__arg)) {
  __isset.mechanism = true;
  __isset.request = true;
  __isset.mechanisms = true;
}

void SaslStart::__clear() {
  // clear all fields
  mechanism = apache::thrift::StringTraits< std::string>::fromStringLiteral("");
  ::apache::thrift::Cpp2Ops<  ::apache::thrift::sasl::SaslRequest>::clear(&request);
  mechanisms.clear();
  __isset = {};
}

bool SaslStart::operator==(const SaslStart& rhs) const {
  if (!((mechanism == rhs.mechanism))) {
    return false;
  }
  if (__isset.request != rhs.__isset.request) {
    return false;
  }
  else if (__isset.request && !((request == rhs.request))) {
    return false;
  }
  if (__isset.mechanisms != rhs.__isset.mechanisms) {
    return false;
  }
  else if (__isset.mechanisms && !((mechanisms == rhs.mechanisms))) {
    return false;
  }
  return true;
}

const  ::apache::thrift::sasl::SaslRequest* SaslStart::get_request() const& {
  return __isset.request ? std::addressof(request) : nullptr;
}

 ::apache::thrift::sasl::SaslRequest* SaslStart::get_request() & {
  return __isset.request ? std::addressof(request) : nullptr;
}

const std::vector<std::string>* SaslStart::get_mechanisms() const& {
  return __isset.mechanisms ? std::addressof(mechanisms) : nullptr;
}

std::vector<std::string>* SaslStart::get_mechanisms() & {
  return __isset.mechanisms ? std::addressof(mechanisms) : nullptr;
}

void SaslStart::translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "mechanism") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "request") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_STRUCT;
  }
  else if (_fname == "mechanisms") {
    fid = 3;
    _ftype = apache::thrift::protocol::T_LIST;
  }
}

void swap(SaslStart& a, SaslStart& b) {
  using ::std::swap;
  swap(a.mechanism, b.mechanism);
  swap(a.request, b.request);
  swap(a.mechanisms, b.mechanisms);
  swap(a.__isset, b.__isset);
}

template uint32_t SaslStart::read<>(apache::thrift::BinaryProtocolReader*);
template uint32_t SaslStart::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t SaslStart::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t SaslStart::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t SaslStart::read<>(apache::thrift::CompactProtocolReader*);
template uint32_t SaslStart::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t SaslStart::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t SaslStart::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}} // apache::thrift::sasl