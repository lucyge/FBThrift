/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/lib/thrift/gen-cpp2/frozen_types.h"
#include "thrift/lib/thrift/gen-cpp2/frozen_types.tcc"

#include <algorithm>
#include <folly/Indestructible.h>

#include "thrift/lib/thrift/gen-cpp2/frozen_data.h"

namespace apache { namespace thrift { namespace frozen { namespace schema { namespace cpp2 {

Field::Field(apache::thrift::FragileConstructor, int16_t layoutId__arg, int16_t offset__arg) :
    layoutId(std::move(layoutId__arg)),
    offset(std::move(offset__arg)) {
  __isset.layoutId = true;
  __isset.offset = true;
}

void Field::__clear() {
  // clear all fields
  layoutId = 0;
  offset = static_cast<int16_t>(0);
  __isset = {};
}

bool Field::operator==(const Field& rhs) const {
  if (!((layoutId == rhs.layoutId))) {
    return false;
  }
  if (!((offset == rhs.offset))) {
    return false;
  }
  return true;
}

void Field::translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "layoutId") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_I16;
  }
  else if (_fname == "offset") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_I16;
  }
}

void swap(Field& a, Field& b) {
  using ::std::swap;
  swap(a.layoutId, b.layoutId);
  swap(a.offset, b.offset);
  swap(a.__isset, b.__isset);
}

template uint32_t Field::read<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Field::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Field::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Field::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Field::read<>(apache::thrift::CompactProtocolReader*);
template uint32_t Field::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Field::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Field::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}}}} // apache::thrift::frozen::schema::cpp2
namespace apache { namespace thrift { namespace frozen { namespace schema { namespace cpp2 {

Layout::Layout(apache::thrift::FragileConstructor, int32_t size__arg, int16_t bits__arg, std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Field> fields__arg, std::string typeName__arg) :
    size(std::move(size__arg)),
    bits(std::move(bits__arg)),
    fields(std::move(fields__arg)),
    typeName(std::move(typeName__arg)) {
  __isset.size = true;
  __isset.bits = true;
  __isset.fields = true;
  __isset.typeName = true;
}

void Layout::__clear() {
  // clear all fields
  size = 0;
  bits = static_cast<int16_t>(0);
  fields.clear();
  typeName = apache::thrift::StringTraits< std::string>::fromStringLiteral("");
  __isset = {};
}

bool Layout::operator==(const Layout& rhs) const {
  if (!((size == rhs.size))) {
    return false;
  }
  if (!((bits == rhs.bits))) {
    return false;
  }
  if (!((fields == rhs.fields))) {
    return false;
  }
  if (!((typeName == rhs.typeName))) {
    return false;
  }
  return true;
}

const std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Field>& Layout::get_fields() const& {
  return fields;
}

std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Field> Layout::get_fields() && {
  return std::move(fields);
}

void Layout::translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "size") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_I32;
  }
  else if (_fname == "bits") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_I16;
  }
  else if (_fname == "fields") {
    fid = 3;
    _ftype = apache::thrift::protocol::T_MAP;
  }
  else if (_fname == "typeName") {
    fid = 4;
    _ftype = apache::thrift::protocol::T_STRING;
  }
}

void swap(Layout& a, Layout& b) {
  using ::std::swap;
  swap(a.size, b.size);
  swap(a.bits, b.bits);
  swap(a.fields, b.fields);
  swap(a.typeName, b.typeName);
  swap(a.__isset, b.__isset);
}

template uint32_t Layout::read<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Layout::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Layout::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Layout::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Layout::read<>(apache::thrift::CompactProtocolReader*);
template uint32_t Layout::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Layout::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Layout::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}}}} // apache::thrift::frozen::schema::cpp2
namespace apache { namespace thrift { namespace frozen { namespace schema { namespace cpp2 {

Schema::Schema(apache::thrift::FragileConstructor, int32_t fileVersion__arg, bool relaxTypeChecks__arg, std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Layout> layouts__arg, int16_t rootLayout__arg) :
    fileVersion(std::move(fileVersion__arg)),
    relaxTypeChecks(std::move(relaxTypeChecks__arg)),
    layouts(std::move(layouts__arg)),
    rootLayout(std::move(rootLayout__arg)) {
  __isset.fileVersion = true;
  __isset.relaxTypeChecks = true;
  __isset.layouts = true;
  __isset.rootLayout = true;
}

void Schema::__clear() {
  // clear all fields
  fileVersion = 0;
  relaxTypeChecks = 0;
  layouts.clear();
  rootLayout = static_cast<int16_t>(0);
  __isset = {};
}

bool Schema::operator==(const Schema& rhs) const {
  if (!((fileVersion == rhs.fileVersion))) {
    return false;
  }
  if (!((relaxTypeChecks == rhs.relaxTypeChecks))) {
    return false;
  }
  if (!((layouts == rhs.layouts))) {
    return false;
  }
  if (!((rootLayout == rhs.rootLayout))) {
    return false;
  }
  return true;
}

const std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Layout>& Schema::get_layouts() const& {
  return layouts;
}

std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Layout> Schema::get_layouts() && {
  return std::move(layouts);
}

void Schema::translateFieldName(FOLLY_MAYBE_UNUSED folly::StringPiece _fname, FOLLY_MAYBE_UNUSED int16_t& fid, FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "fileVersion") {
    fid = 4;
    _ftype = apache::thrift::protocol::T_I32;
  }
  else if (_fname == "relaxTypeChecks") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_BOOL;
  }
  else if (_fname == "layouts") {
    fid = 2;
    _ftype = apache::thrift::protocol::T_MAP;
  }
  else if (_fname == "rootLayout") {
    fid = 3;
    _ftype = apache::thrift::protocol::T_I16;
  }
}

void swap(Schema& a, Schema& b) {
  using ::std::swap;
  swap(a.fileVersion, b.fileVersion);
  swap(a.relaxTypeChecks, b.relaxTypeChecks);
  swap(a.layouts, b.layouts);
  swap(a.rootLayout, b.rootLayout);
  swap(a.__isset, b.__isset);
}

template uint32_t Schema::read<>(apache::thrift::BinaryProtocolReader*);
template uint32_t Schema::write<>(apache::thrift::BinaryProtocolWriter*) const;
template uint32_t Schema::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Schema::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
template uint32_t Schema::read<>(apache::thrift::CompactProtocolReader*);
template uint32_t Schema::write<>(apache::thrift::CompactProtocolWriter*) const;
template uint32_t Schema::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
template uint32_t Schema::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

}}}}} // apache::thrift::frozen::schema::cpp2