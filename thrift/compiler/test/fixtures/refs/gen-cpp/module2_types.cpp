/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/refs/gen-cpp/module2_types.h"
#include "thrift/compiler/test/fixtures/refs/gen-cpp/module2_data.h"

#include "thrift/compiler/test/fixtures/refs/gen-cpp/module2_reflection.h"

#include <algorithm>
#include <string.h>

#include <folly/Indestructible.h>



const uint64_t StructUsingOtherNamespace::_reflection_id;
void StructUsingOtherNamespace::_reflection_register(::apache::thrift::reflection::Schema& schema) {
   ::module2_reflection_::reflectionInitializer_8285996275179549516(schema);
}

StructUsingOtherNamespace::StructUsingOtherNamespace(const StructUsingOtherNamespace& src0) {
  if (src0.other)
    other.reset(new  ::cpp1::Included(*src0.other));
}
bool StructUsingOtherNamespace::operator == (const StructUsingOtherNamespace & rhs) const {
  if (bool(other) != bool(rhs.other))
    return false;
  else if (bool(other) && !(*other == *rhs.other))
    return false;
  return true;
}

void StructUsingOtherNamespace::readFromJson(const char* jsonText, size_t len, const folly::json::serialization_opts& opts)
{
  folly::dynamic parsed = folly::parseJson(folly::StringPiece(jsonText, len), opts);
  if (parsed["other"] != nullptr) {
    this->other.reset(new  ::cpp1::Included());
    this->other->readFromJson(folly::toJson(parsed["other"]).c_str(), opts);
  }}
void StructUsingOtherNamespace::readFromJson(const char* jsonText, const folly::json::serialization_opts& opts)
{
  readFromJson(jsonText, strlen(jsonText), opts);
}

void StructUsingOtherNamespace::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "other") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_STRUCT;
  }
};

uint32_t StructUsingOtherNamespace::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string _fname;
  apache::thrift::protocol::TType _ftype;
  int16_t fid;

  ::apache::thrift::reflection::Schema * schema = iprot->getSchema();
  if (schema != nullptr) {
     ::module2_reflection_::reflectionInitializer_8285996275179549516(*schema);
    iprot->setNextStructType(StructUsingOtherNamespace::_reflection_id);
  }
  xfer += iprot->readStructBegin(_fname);

  using apache::thrift::protocol::TProtocolException;



  while (true)
  {
    xfer += iprot->readFieldBegin(_fname, _ftype, fid);
    if (_ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (_ftype == apache::thrift::protocol::T_STRUCT) {
          using element_type = typename std::remove_const<typename std::remove_reference<decltype(this->other)>::type::element_type>::type;
          std::unique_ptr<element_type> _ptype2(new element_type());
          xfer += _ptype2->read(iprot);
          this->other = std::move(_ptype2);
          if (false) {
          } else if (this->other->__isset.some_val) {
          } else { this->other = nullptr; }
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      default:
        xfer += iprot->skip(_ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

void StructUsingOtherNamespace::__clear() {
  if (other) other->__clear();
  __isset.__clear();
}
uint32_t StructUsingOtherNamespace::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("StructUsingOtherNamespace");
  if (this->other) {
    xfer += oprot->writeFieldBegin("other", apache::thrift::protocol::T_STRUCT, 1);
    if (this->other) {xfer += this->other->write(oprot); 
} else {oprot->writeStructBegin("Included"); oprot->writeStructEnd(); oprot->writeFieldStop();}
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(StructUsingOtherNamespace &a, StructUsingOtherNamespace &b) {
  using ::std::swap;
  (void)a;
  (void)b;
  swap(a.other, b.other);
  swap(a.__isset, b.__isset);
}

void merge(const StructUsingOtherNamespace& from, StructUsingOtherNamespace& to) {
  using apache::thrift::merge;
  merge(from.other, to.other);
}

void merge(StructUsingOtherNamespace&& from, StructUsingOtherNamespace& to) {
  using apache::thrift::merge;
  merge(std::move(from.other), to.other);
}


