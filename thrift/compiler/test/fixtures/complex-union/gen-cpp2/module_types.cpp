/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "src/gen-cpp2/module_types.h"
#include "src/gen-cpp2/module_types.tcc"

#include <algorithm>
#include <folly/Indestructible.h>

#include "src/gen-cpp2/module_data.h"

namespace cpp2 {

void ComplexUnion::__clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::intValue:
    {
      destruct(value_.intValue);
      break;
    }
    case Type::stringValue:
    {
      destruct(value_.stringValue);
      break;
    }
    case Type::intListValue:
    {
      destruct(value_.intListValue);
      break;
    }
    case Type::stringListValue:
    {
      destruct(value_.stringListValue);
      break;
    }
    case Type::typedefValue:
    {
      destruct(value_.typedefValue);
      break;
    }
    case Type::stringRef:
    {
      destruct(value_.stringRef);
      break;
    }
    default:
    {
      assert(false);
      break;
    }
  }
  type_ = Type::__EMPTY__;
}

bool ComplexUnion::operator==(const ComplexUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::intValue:
    {
      return value_.intValue == rhs.value_.intValue;
    }
    case Type::stringValue:
    {
      return value_.stringValue == rhs.value_.stringValue;
    }
    case Type::intListValue:
    {
      return value_.intListValue == rhs.value_.intListValue;
    }
    case Type::stringListValue:
    {
      return value_.stringListValue == rhs.value_.stringListValue;
    }
    case Type::typedefValue:
    {
      return value_.typedefValue == rhs.value_.typedefValue;
    }
    case Type::stringRef:
    {
      return *value_.stringRef == *rhs.value_.stringRef;
    }
    default:
    {
      return true;
    }
  }
}
void ComplexUnion::translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "intValue") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_I64;
  }
  else if (_fname == "stringValue") {
    fid = 5;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "intListValue") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_LIST;
  }
  else if (_fname == "stringListValue") {
    fid = 3;
    _ftype = apache::thrift::protocol::T_LIST;
  }
  else if (_fname == "typedefValue") {
    fid = 9;
    _ftype = apache::thrift::protocol::T_MAP;
  }
  else if (_fname == "stringRef") {
    fid = 14;
    _ftype = apache::thrift::protocol::T_STRING;
  }
}

void swap(ComplexUnion& a, ComplexUnion& b) {
  ComplexUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template uint32_t ComplexUnion::read<>(apache::thrift::BinaryProtocolReader*);
template uint32_t ComplexUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t ComplexUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t ComplexUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t ComplexUnion::read<>(apache::thrift::CompactProtocolReader*);
template uint32_t ComplexUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t ComplexUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t ComplexUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // cpp2
namespace cpp2 {

void VirtualComplexUnion::__clear() {
  // clear all fields
  if (type_ == Type::__EMPTY__) { return; }
  switch(type_) {
    case Type::thingOne:
    {
      destruct(value_.thingOne);
      break;
    }
    case Type::thingTwo:
    {
      destruct(value_.thingTwo);
      break;
    }
    default:
    {
      assert(false);
      break;
    }
  }
  type_ = Type::__EMPTY__;
}

bool VirtualComplexUnion::operator==(const VirtualComplexUnion& rhs) const {
  if (type_ != rhs.type_) { return false; }
  switch(type_) {
    case Type::thingOne:
    {
      return value_.thingOne == rhs.value_.thingOne;
    }
    case Type::thingTwo:
    {
      return value_.thingTwo == rhs.value_.thingTwo;
    }
    default:
    {
      return true;
    }
  }
}
void VirtualComplexUnion::translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "thingOne") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "thingTwo") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_STRING;
  }
}

void swap(VirtualComplexUnion& a, VirtualComplexUnion& b) {
  VirtualComplexUnion temp(std::move(a));
  a = std::move(b);
  b = std::move(temp);
}

template uint32_t VirtualComplexUnion::read<>(apache::thrift::BinaryProtocolReader*);
template uint32_t VirtualComplexUnion::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t VirtualComplexUnion::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t VirtualComplexUnion::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t VirtualComplexUnion::read<>(apache::thrift::CompactProtocolReader*);
template uint32_t VirtualComplexUnion::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t VirtualComplexUnion::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t VirtualComplexUnion::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

} // cpp2