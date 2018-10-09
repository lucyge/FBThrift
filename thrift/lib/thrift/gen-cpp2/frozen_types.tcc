/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "thrift/lib/thrift/gen-cpp2/frozen_types.h"

#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>

#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>

namespace apache { namespace thrift { namespace frozen { namespace schema { namespace cpp2 {

template <class Protocol_>
uint32_t Field::read(Protocol_* iprot) {
  uint32_t xfer = 0;
  std::string _fname;
  apache::thrift::protocol::TType _ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(_fname);

  using apache::thrift::TProtocolException;


  while (true) {
    xfer += iprot->readFieldBegin(_fname, _ftype, fid);
    if (_ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    if (iprot->kUsesFieldNames()) {
      this->translateFieldName(_fname, fid, _ftype);
    }
    switch (fid) {
      case 1:
      {
        if (_ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->layoutId);
          this->__isset.layoutId = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 2:
      {
        if (_ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->offset);
          this->__isset.offset = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      default:
      {
        xfer += iprot->skip(_ftype);
        break;
      }
    }
    xfer += iprot->readFieldEnd();
  }
  xfer += iprot->readStructEnd();

  return xfer;
}

template <class Protocol_>
uint32_t Field::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Field");
  xfer += prot_->serializedFieldSize("layoutId", apache::thrift::protocol::T_I16, 1);
  xfer += prot_->serializedSizeI16(this->layoutId);
  xfer += prot_->serializedFieldSize("offset", apache::thrift::protocol::T_I16, 2);
  xfer += prot_->serializedSizeI16(this->offset);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Field::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Field");
  xfer += prot_->serializedFieldSize("layoutId", apache::thrift::protocol::T_I16, 1);
  xfer += prot_->serializedSizeI16(this->layoutId);
  xfer += prot_->serializedFieldSize("offset", apache::thrift::protocol::T_I16, 2);
  xfer += prot_->serializedSizeI16(this->offset);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Field::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("Field");
  xfer += prot_->writeFieldBegin("layoutId", apache::thrift::protocol::T_I16, 1);
  xfer += prot_->writeI16(this->layoutId);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("offset", apache::thrift::protocol::T_I16, 2);
  xfer += prot_->writeI16(this->offset);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

}}}}} // apache::thrift::frozen::schema::cpp2
namespace apache { namespace thrift { namespace frozen { namespace schema { namespace cpp2 {

template <class Protocol_>
uint32_t Layout::read(Protocol_* iprot) {
  uint32_t xfer = 0;
  std::string _fname;
  apache::thrift::protocol::TType _ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(_fname);

  using apache::thrift::TProtocolException;


  while (true) {
    xfer += iprot->readFieldBegin(_fname, _ftype, fid);
    if (_ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    if (iprot->kUsesFieldNames()) {
      this->translateFieldName(_fname, fid, _ftype);
    }
    switch (fid) {
      case 1:
      {
        if (_ftype == apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->size);
          this->__isset.size = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 2:
      {
        if (_ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->bits);
          this->__isset.bits = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 3:
      {
        if (_ftype == apache::thrift::protocol::T_MAP) {
          this->fields = std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Field>();
          xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Field>>::read(*iprot, this->fields);
          this->__isset.fields = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 4:
      {
        if (_ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->typeName);
          this->__isset.typeName = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      default:
      {
        xfer += iprot->skip(_ftype);
        break;
      }
    }
    xfer += iprot->readFieldEnd();
  }
  xfer += iprot->readStructEnd();

  return xfer;
}

template <class Protocol_>
uint32_t Layout::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Layout");
  xfer += prot_->serializedFieldSize("size", apache::thrift::protocol::T_I32, 1);
  xfer += prot_->serializedSizeI32(this->size);
  xfer += prot_->serializedFieldSize("bits", apache::thrift::protocol::T_I16, 2);
  xfer += prot_->serializedSizeI16(this->bits);
  xfer += prot_->serializedFieldSize("fields", apache::thrift::protocol::T_MAP, 3);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Field>>::serializedSize<false>(*prot_, this->fields);
  xfer += prot_->serializedFieldSize("typeName", apache::thrift::protocol::T_STRING, 4);
  xfer += prot_->serializedSizeString(this->typeName);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Layout::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Layout");
  xfer += prot_->serializedFieldSize("size", apache::thrift::protocol::T_I32, 1);
  xfer += prot_->serializedSizeI32(this->size);
  xfer += prot_->serializedFieldSize("bits", apache::thrift::protocol::T_I16, 2);
  xfer += prot_->serializedSizeI16(this->bits);
  xfer += prot_->serializedFieldSize("fields", apache::thrift::protocol::T_MAP, 3);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Field>>::serializedSize<false>(*prot_, this->fields);
  xfer += prot_->serializedFieldSize("typeName", apache::thrift::protocol::T_STRING, 4);
  xfer += prot_->serializedSizeString(this->typeName);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Layout::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("Layout");
  xfer += prot_->writeFieldBegin("size", apache::thrift::protocol::T_I32, 1);
  xfer += prot_->writeI32(this->size);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("bits", apache::thrift::protocol::T_I16, 2);
  xfer += prot_->writeI16(this->bits);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("fields", apache::thrift::protocol::T_MAP, 3);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Field>>::write(*prot_, this->fields);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("typeName", apache::thrift::protocol::T_STRING, 4);
  xfer += prot_->writeString(this->typeName);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

}}}}} // apache::thrift::frozen::schema::cpp2
namespace apache { namespace thrift { namespace frozen { namespace schema { namespace cpp2 {

template <class Protocol_>
uint32_t Schema::read(Protocol_* iprot) {
  uint32_t xfer = 0;
  std::string _fname;
  apache::thrift::protocol::TType _ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(_fname);

  using apache::thrift::TProtocolException;


  while (true) {
    xfer += iprot->readFieldBegin(_fname, _ftype, fid);
    if (_ftype == apache::thrift::protocol::T_STOP) {
      break;
    }
    if (iprot->kUsesFieldNames()) {
      this->translateFieldName(_fname, fid, _ftype);
    }
    switch (fid) {
      case 4:
      {
        if (_ftype == apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->fileVersion);
          this->__isset.fileVersion = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 1:
      {
        if (_ftype == apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->relaxTypeChecks);
          this->__isset.relaxTypeChecks = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 2:
      {
        if (_ftype == apache::thrift::protocol::T_MAP) {
          this->layouts = std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Layout>();
          xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Layout>>::read(*iprot, this->layouts);
          this->__isset.layouts = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 3:
      {
        if (_ftype == apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->rootLayout);
          this->__isset.rootLayout = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      default:
      {
        xfer += iprot->skip(_ftype);
        break;
      }
    }
    xfer += iprot->readFieldEnd();
  }
  xfer += iprot->readStructEnd();

  return xfer;
}

template <class Protocol_>
uint32_t Schema::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Schema");
  xfer += prot_->serializedFieldSize("fileVersion", apache::thrift::protocol::T_I32, 4);
  xfer += prot_->serializedSizeI32(this->fileVersion);
  xfer += prot_->serializedFieldSize("relaxTypeChecks", apache::thrift::protocol::T_BOOL, 1);
  xfer += prot_->serializedSizeBool(this->relaxTypeChecks);
  xfer += prot_->serializedFieldSize("layouts", apache::thrift::protocol::T_MAP, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Layout>>::serializedSize<false>(*prot_, this->layouts);
  xfer += prot_->serializedFieldSize("rootLayout", apache::thrift::protocol::T_I16, 3);
  xfer += prot_->serializedSizeI16(this->rootLayout);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Schema::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("Schema");
  xfer += prot_->serializedFieldSize("fileVersion", apache::thrift::protocol::T_I32, 4);
  xfer += prot_->serializedSizeI32(this->fileVersion);
  xfer += prot_->serializedFieldSize("relaxTypeChecks", apache::thrift::protocol::T_BOOL, 1);
  xfer += prot_->serializedSizeBool(this->relaxTypeChecks);
  xfer += prot_->serializedFieldSize("layouts", apache::thrift::protocol::T_MAP, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Layout>>::serializedSize<false>(*prot_, this->layouts);
  xfer += prot_->serializedFieldSize("rootLayout", apache::thrift::protocol::T_I16, 3);
  xfer += prot_->serializedSizeI16(this->rootLayout);
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t Schema::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("Schema");
  xfer += prot_->writeFieldBegin("fileVersion", apache::thrift::protocol::T_I32, 4);
  xfer += prot_->writeI32(this->fileVersion);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("relaxTypeChecks", apache::thrift::protocol::T_BOOL, 1);
  xfer += prot_->writeBool(this->relaxTypeChecks);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("layouts", apache::thrift::protocol::T_MAP, 2);
  xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::integral, ::apache::thrift::type_class::structure>, std::map<int16_t,  ::apache::thrift::frozen::schema::cpp2::Layout>>::write(*prot_, this->layouts);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldBegin("rootLayout", apache::thrift::protocol::T_I16, 3);
  xfer += prot_->writeI16(this->rootLayout);
  xfer += prot_->writeFieldEnd();
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

}}}}} // apache::thrift::frozen::schema::cpp2
