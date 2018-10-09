/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/lib/thrift/gen-cpp/reflection_types.h"
#include "thrift/lib/thrift/gen-cpp/reflection_data.h"

#include <algorithm>
#include <string.h>

#include <folly/Indestructible.h>

namespace apache { namespace thrift { namespace reflection {

const typename _Type_EnumMapFactory::ValuesToNamesMapType _Type_VALUES_TO_NAMES = _Type_EnumMapFactory::makeValuesToNamesMap();

const typename _Type_EnumMapFactory::NamesToValuesMapType _Type_NAMES_TO_VALUES = _Type_EnumMapFactory::makeNamesToValuesMap();

}}} // namespace
namespace apache { namespace thrift {
template <>const std::size_t TEnumTraits< ::apache::thrift::reflection::Type>::size = 16;
template <>const folly::Range<const  ::apache::thrift::reflection::Type*> TEnumTraits< ::apache::thrift::reflection::Type>::values = folly::range( ::apache::thrift::reflection::_TypeEnumDataStorage::values);
template <>const folly::Range<const folly::StringPiece*> TEnumTraits< ::apache::thrift::reflection::Type>::names = folly::range( ::apache::thrift::reflection::_TypeEnumDataStorage::names);

template<>
const char* TEnumTraits< ::apache::thrift::reflection::Type>::findName( ::apache::thrift::reflection::Type value) {
  static const auto map = folly::Indestructible< ::apache::thrift::reflection::_Type_EnumMapFactory::ValuesToNamesMapType>{ ::apache::thrift::reflection::_Type_EnumMapFactory::makeValuesToNamesMap()};
  return findName(*map, value);
}

template<>
bool TEnumTraits< ::apache::thrift::reflection::Type>::findValue(const char* name,  ::apache::thrift::reflection::Type* out) {
  static const auto map = folly::Indestructible< ::apache::thrift::reflection::_Type_EnumMapFactory::NamesToValuesMapType>{ ::apache::thrift::reflection::_Type_EnumMapFactory::makeNamesToValuesMap()};
  return findValue(*map, name, out);
}
}} // apache::thrift

namespace apache { namespace thrift { namespace reflection {
const uint64_t StructField::_reflection_id;
void StructField::_reflection_register(::apache::thrift::reflection::Schema& schema) {
   ::apache::thrift::reflection::reflection_reflection_::reflectionInitializer_214309804125196972(schema);
}

bool StructField::operator == (const StructField & rhs) const {
  if (!(this->isRequired == rhs.isRequired))
    return false;
  if (!(this->type == rhs.type))
    return false;
  if (!(this->name == rhs.name))
    return false;
  if (__isset.annotations != rhs.__isset.annotations)
    return false;
  else if (__isset.annotations && !(annotations == rhs.annotations))
    return false;
  if (!(this->order == rhs.order))
    return false;
  return true;
}

void StructField::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "isRequired") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_BOOL;
  }
  else if (_fname == "type") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_I64;
  }
  else if (_fname == "name") {
    fid = 3;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "annotations") {
    fid = 4;
    _ftype = apache::thrift::protocol::T_MAP;
  }
  else if (_fname == "order") {
    fid = 5;
    _ftype = apache::thrift::protocol::T_I16;
  }
};

void StructField::__clear() {
  isRequired = 0;
  type = 0;
  name = "";
  annotations.clear();
  order = 0;
  __isset.__clear();
}
void swap(StructField &a, StructField &b) {
  using ::std::swap;
  (void)a;
  (void)b;
  swap(a.isRequired, b.isRequired);
  swap(a.type, b.type);
  swap(a.name, b.name);
  swap(a.annotations, b.annotations);
  swap(a.order, b.order);
  swap(a.__isset, b.__isset);
}

void merge(const StructField& from, StructField& to) {
  using apache::thrift::merge;
  merge(from.isRequired, to.isRequired);
  to.__isset.isRequired = to.__isset.isRequired || from.__isset.isRequired;
  merge(from.type, to.type);
  to.__isset.type = to.__isset.type || from.__isset.type;
  merge(from.name, to.name);
  to.__isset.name = to.__isset.name || from.__isset.name;
  if (from.__isset.annotations) {
    merge(from.annotations, to.annotations);
    to.__isset.annotations = true;
  }
  merge(from.order, to.order);
  to.__isset.order = to.__isset.order || from.__isset.order;
}

void merge(StructField&& from, StructField& to) {
  using apache::thrift::merge;
  merge(std::move(from.isRequired), to.isRequired);
  to.__isset.isRequired = to.__isset.isRequired || from.__isset.isRequired;
  merge(std::move(from.type), to.type);
  to.__isset.type = to.__isset.type || from.__isset.type;
  merge(std::move(from.name), to.name);
  to.__isset.name = to.__isset.name || from.__isset.name;
  if (from.__isset.annotations) {
    merge(std::move(from.annotations), to.annotations);
    to.__isset.annotations = true;
  }
  merge(std::move(from.order), to.order);
  to.__isset.order = to.__isset.order || from.__isset.order;
}

const uint64_t DataType::_reflection_id;
void DataType::_reflection_register(::apache::thrift::reflection::Schema& schema) {
   ::apache::thrift::reflection::reflection_reflection_::reflectionInitializer_4733295045172396908(schema);
}

bool DataType::operator == (const DataType & rhs) const {
  if (!(this->name == rhs.name))
    return false;
  if (__isset.fields != rhs.__isset.fields)
    return false;
  else if (__isset.fields && !(fields == rhs.fields))
    return false;
  if (__isset.mapKeyType != rhs.__isset.mapKeyType)
    return false;
  else if (__isset.mapKeyType && !(mapKeyType == rhs.mapKeyType))
    return false;
  if (__isset.valueType != rhs.__isset.valueType)
    return false;
  else if (__isset.valueType && !(valueType == rhs.valueType))
    return false;
  if (__isset.enumValues != rhs.__isset.enumValues)
    return false;
  else if (__isset.enumValues && !(enumValues == rhs.enumValues))
    return false;
  return true;
}

void DataType::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "name") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_STRING;
  }
  else if (_fname == "fields") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_MAP;
  }
  else if (_fname == "mapKeyType") {
    fid = 3;
    _ftype = apache::thrift::protocol::T_I64;
  }
  else if (_fname == "valueType") {
    fid = 4;
    _ftype = apache::thrift::protocol::T_I64;
  }
  else if (_fname == "enumValues") {
    fid = 5;
    _ftype = apache::thrift::protocol::T_MAP;
  }
};

void DataType::__clear() {
  name = "";
  fields.clear();
  mapKeyType = 0;
  valueType = 0;
  enumValues.clear();
  __isset.__clear();
}
void swap(DataType &a, DataType &b) {
  using ::std::swap;
  (void)a;
  (void)b;
  swap(a.name, b.name);
  swap(a.fields, b.fields);
  swap(a.mapKeyType, b.mapKeyType);
  swap(a.valueType, b.valueType);
  swap(a.enumValues, b.enumValues);
  swap(a.__isset, b.__isset);
}

void merge(const DataType& from, DataType& to) {
  using apache::thrift::merge;
  merge(from.name, to.name);
  to.__isset.name = to.__isset.name || from.__isset.name;
  if (from.__isset.fields) {
    merge(from.fields, to.fields);
    to.__isset.fields = true;
  }
  if (from.__isset.mapKeyType) {
    merge(from.mapKeyType, to.mapKeyType);
    to.__isset.mapKeyType = true;
  }
  if (from.__isset.valueType) {
    merge(from.valueType, to.valueType);
    to.__isset.valueType = true;
  }
  if (from.__isset.enumValues) {
    merge(from.enumValues, to.enumValues);
    to.__isset.enumValues = true;
  }
}

void merge(DataType&& from, DataType& to) {
  using apache::thrift::merge;
  merge(std::move(from.name), to.name);
  to.__isset.name = to.__isset.name || from.__isset.name;
  if (from.__isset.fields) {
    merge(std::move(from.fields), to.fields);
    to.__isset.fields = true;
  }
  if (from.__isset.mapKeyType) {
    merge(std::move(from.mapKeyType), to.mapKeyType);
    to.__isset.mapKeyType = true;
  }
  if (from.__isset.valueType) {
    merge(std::move(from.valueType), to.valueType);
    to.__isset.valueType = true;
  }
  if (from.__isset.enumValues) {
    merge(std::move(from.enumValues), to.enumValues);
    to.__isset.enumValues = true;
  }
}

const uint64_t Schema::_reflection_id;
void Schema::_reflection_register(::apache::thrift::reflection::Schema& schema) {
   ::apache::thrift::reflection::reflection_reflection_::reflectionInitializer_6902704939566307148(schema);
}

bool Schema::operator == (const Schema & rhs) const {
  if (!(this->dataTypes == rhs.dataTypes))
    return false;
  if (!(this->names == rhs.names))
    return false;
  return true;
}

void Schema::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "dataTypes") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_MAP;
  }
  else if (_fname == "names") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_MAP;
  }
};

void Schema::__clear() {
  dataTypes.clear();
  names.clear();
  __isset.__clear();
}
void swap(Schema &a, Schema &b) {
  using ::std::swap;
  (void)a;
  (void)b;
  swap(a.dataTypes, b.dataTypes);
  swap(a.names, b.names);
  swap(a.__isset, b.__isset);
}

void merge(const Schema& from, Schema& to) {
  using apache::thrift::merge;
  merge(from.dataTypes, to.dataTypes);
  to.__isset.dataTypes = to.__isset.dataTypes || from.__isset.dataTypes;
  merge(from.names, to.names);
  to.__isset.names = to.__isset.names || from.__isset.names;
}

void merge(Schema&& from, Schema& to) {
  using apache::thrift::merge;
  merge(std::move(from.dataTypes), to.dataTypes);
  to.__isset.dataTypes = to.__isset.dataTypes || from.__isset.dataTypes;
  merge(std::move(from.names), to.names);
  to.__isset.names = to.__isset.names || from.__isset.names;
}

}}} // namespace
