/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include "thrift/lib/thrift/gen-cpp2/RpcMetadata_types.h"

#include <thrift/lib/cpp2/GeneratedSerializationCodeHelper.h>

#include <thrift/lib/cpp2/protocol/BinaryProtocol.h>
#include <thrift/lib/cpp2/protocol/CompactProtocol.h>

namespace apache { namespace thrift {

}} // apache::thrift
namespace std {

} // std
namespace apache { namespace thrift {

}} // apache::thrift
namespace apache { namespace thrift {

}} // apache::thrift
namespace std {

} // std
namespace apache { namespace thrift {

}} // apache::thrift
namespace apache { namespace thrift {

}} // apache::thrift
namespace std {

} // std
namespace apache { namespace thrift {

}} // apache::thrift
namespace apache { namespace thrift {

template <class Protocol_>
uint32_t RequestRpcMetadata::read(Protocol_* iprot) {
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
          xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::ProtocolId>::read(*iprot, this->protocol);
          this->__isset.protocol = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 2:
      {
        if (_ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 3:
      {
        if (_ftype == apache::thrift::protocol::T_I32) {
          xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::RpcKind>::read(*iprot, this->kind);
          this->__isset.kind = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 4:
      {
        if (_ftype == apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->seqId);
          this->__isset.seqId = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 5:
      {
        if (_ftype == apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->clientTimeoutMs);
          this->__isset.clientTimeoutMs = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 6:
      {
        if (_ftype == apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->queueTimeoutMs);
          this->__isset.queueTimeoutMs = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 7:
      {
        if (_ftype == apache::thrift::protocol::T_I32) {
          xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::RpcPriority>::read(*iprot, this->priority);
          this->__isset.priority = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 8:
      {
        if (_ftype == apache::thrift::protocol::T_MAP) {
          this->otherMetadata = std::map<std::string, std::string>();
          xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::string>, std::map<std::string, std::string>>::read(*iprot, this->otherMetadata);
          this->__isset.otherMetadata = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 9:
      {
        if (_ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->host);
          this->__isset.host = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 10:
      {
        if (_ftype == apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->url);
          this->__isset.url = true;
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
uint32_t RequestRpcMetadata::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("RequestRpcMetadata");
  if (this->__isset.protocol) {
    xfer += prot_->serializedFieldSize("protocol", apache::thrift::protocol::T_I32, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::ProtocolId>::serializedSize<false>(*prot_, this->protocol);
  }
  if (this->__isset.name) {
    xfer += prot_->serializedFieldSize("name", apache::thrift::protocol::T_STRING, 2);
    xfer += prot_->serializedSizeString(this->name);
  }
  if (this->__isset.kind) {
    xfer += prot_->serializedFieldSize("kind", apache::thrift::protocol::T_I32, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::RpcKind>::serializedSize<false>(*prot_, this->kind);
  }
  if (this->__isset.seqId) {
    xfer += prot_->serializedFieldSize("seqId", apache::thrift::protocol::T_I32, 4);
    xfer += prot_->serializedSizeI32(this->seqId);
  }
  if (this->__isset.clientTimeoutMs) {
    xfer += prot_->serializedFieldSize("clientTimeoutMs", apache::thrift::protocol::T_I32, 5);
    xfer += prot_->serializedSizeI32(this->clientTimeoutMs);
  }
  if (this->__isset.queueTimeoutMs) {
    xfer += prot_->serializedFieldSize("queueTimeoutMs", apache::thrift::protocol::T_I32, 6);
    xfer += prot_->serializedSizeI32(this->queueTimeoutMs);
  }
  if (this->__isset.priority) {
    xfer += prot_->serializedFieldSize("priority", apache::thrift::protocol::T_I32, 7);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::RpcPriority>::serializedSize<false>(*prot_, this->priority);
  }
  if (this->__isset.otherMetadata) {
    xfer += prot_->serializedFieldSize("otherMetadata", apache::thrift::protocol::T_MAP, 8);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::string>, std::map<std::string, std::string>>::serializedSize<false>(*prot_, this->otherMetadata);
  }
  if (this->__isset.host) {
    xfer += prot_->serializedFieldSize("host", apache::thrift::protocol::T_STRING, 9);
    xfer += prot_->serializedSizeString(this->host);
  }
  if (this->__isset.url) {
    xfer += prot_->serializedFieldSize("url", apache::thrift::protocol::T_STRING, 10);
    xfer += prot_->serializedSizeString(this->url);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t RequestRpcMetadata::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("RequestRpcMetadata");
  if (this->__isset.protocol) {
    xfer += prot_->serializedFieldSize("protocol", apache::thrift::protocol::T_I32, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::ProtocolId>::serializedSize<false>(*prot_, this->protocol);
  }
  if (this->__isset.name) {
    xfer += prot_->serializedFieldSize("name", apache::thrift::protocol::T_STRING, 2);
    xfer += prot_->serializedSizeString(this->name);
  }
  if (this->__isset.kind) {
    xfer += prot_->serializedFieldSize("kind", apache::thrift::protocol::T_I32, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::RpcKind>::serializedSize<false>(*prot_, this->kind);
  }
  if (this->__isset.seqId) {
    xfer += prot_->serializedFieldSize("seqId", apache::thrift::protocol::T_I32, 4);
    xfer += prot_->serializedSizeI32(this->seqId);
  }
  if (this->__isset.clientTimeoutMs) {
    xfer += prot_->serializedFieldSize("clientTimeoutMs", apache::thrift::protocol::T_I32, 5);
    xfer += prot_->serializedSizeI32(this->clientTimeoutMs);
  }
  if (this->__isset.queueTimeoutMs) {
    xfer += prot_->serializedFieldSize("queueTimeoutMs", apache::thrift::protocol::T_I32, 6);
    xfer += prot_->serializedSizeI32(this->queueTimeoutMs);
  }
  if (this->__isset.priority) {
    xfer += prot_->serializedFieldSize("priority", apache::thrift::protocol::T_I32, 7);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::RpcPriority>::serializedSize<false>(*prot_, this->priority);
  }
  if (this->__isset.otherMetadata) {
    xfer += prot_->serializedFieldSize("otherMetadata", apache::thrift::protocol::T_MAP, 8);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::string>, std::map<std::string, std::string>>::serializedSize<false>(*prot_, this->otherMetadata);
  }
  if (this->__isset.host) {
    xfer += prot_->serializedFieldSize("host", apache::thrift::protocol::T_STRING, 9);
    xfer += prot_->serializedSizeString(this->host);
  }
  if (this->__isset.url) {
    xfer += prot_->serializedFieldSize("url", apache::thrift::protocol::T_STRING, 10);
    xfer += prot_->serializedSizeString(this->url);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t RequestRpcMetadata::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("RequestRpcMetadata");
  if (this->__isset.protocol) {
    xfer += prot_->writeFieldBegin("protocol", apache::thrift::protocol::T_I32, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::ProtocolId>::write(*prot_, this->protocol);
    xfer += prot_->writeFieldEnd();
  }
  if (this->__isset.name) {
    xfer += prot_->writeFieldBegin("name", apache::thrift::protocol::T_STRING, 2);
    xfer += prot_->writeString(this->name);
    xfer += prot_->writeFieldEnd();
  }
  if (this->__isset.kind) {
    xfer += prot_->writeFieldBegin("kind", apache::thrift::protocol::T_I32, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::RpcKind>::write(*prot_, this->kind);
    xfer += prot_->writeFieldEnd();
  }
  if (this->__isset.seqId) {
    xfer += prot_->writeFieldBegin("seqId", apache::thrift::protocol::T_I32, 4);
    xfer += prot_->writeI32(this->seqId);
    xfer += prot_->writeFieldEnd();
  }
  if (this->__isset.clientTimeoutMs) {
    xfer += prot_->writeFieldBegin("clientTimeoutMs", apache::thrift::protocol::T_I32, 5);
    xfer += prot_->writeI32(this->clientTimeoutMs);
    xfer += prot_->writeFieldEnd();
  }
  if (this->__isset.queueTimeoutMs) {
    xfer += prot_->writeFieldBegin("queueTimeoutMs", apache::thrift::protocol::T_I32, 6);
    xfer += prot_->writeI32(this->queueTimeoutMs);
    xfer += prot_->writeFieldEnd();
  }
  if (this->__isset.priority) {
    xfer += prot_->writeFieldBegin("priority", apache::thrift::protocol::T_I32, 7);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::RpcPriority>::write(*prot_, this->priority);
    xfer += prot_->writeFieldEnd();
  }
  if (this->__isset.otherMetadata) {
    xfer += prot_->writeFieldBegin("otherMetadata", apache::thrift::protocol::T_MAP, 8);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::string>, std::map<std::string, std::string>>::write(*prot_, this->otherMetadata);
    xfer += prot_->writeFieldEnd();
  }
  if (this->__isset.host) {
    xfer += prot_->writeFieldBegin("host", apache::thrift::protocol::T_STRING, 9);
    xfer += prot_->writeString(this->host);
    xfer += prot_->writeFieldEnd();
  }
  if (this->__isset.url) {
    xfer += prot_->writeFieldBegin("url", apache::thrift::protocol::T_STRING, 10);
    xfer += prot_->writeString(this->url);
    xfer += prot_->writeFieldEnd();
  }
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

}} // apache::thrift
namespace apache { namespace thrift {

template <class Protocol_>
uint32_t ResponseRpcMetadata::read(Protocol_* iprot) {
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
          xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::ProtocolId>::read(*iprot, this->protocol);
          this->__isset.protocol = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 2:
      {
        if (_ftype == apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->seqId);
          this->__isset.seqId = true;
        } else {
          xfer += iprot->skip(_ftype);
        }
        break;
      }
      case 3:
      {
        if (_ftype == apache::thrift::protocol::T_MAP) {
          this->otherMetadata = std::map<std::string, std::string>();
          xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::string>, std::map<std::string, std::string>>::read(*iprot, this->otherMetadata);
          this->__isset.otherMetadata = true;
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
uint32_t ResponseRpcMetadata::serializedSize(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("ResponseRpcMetadata");
  if (this->__isset.protocol) {
    xfer += prot_->serializedFieldSize("protocol", apache::thrift::protocol::T_I32, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::ProtocolId>::serializedSize<false>(*prot_, this->protocol);
  }
  if (this->__isset.seqId) {
    xfer += prot_->serializedFieldSize("seqId", apache::thrift::protocol::T_I32, 2);
    xfer += prot_->serializedSizeI32(this->seqId);
  }
  if (this->__isset.otherMetadata) {
    xfer += prot_->serializedFieldSize("otherMetadata", apache::thrift::protocol::T_MAP, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::string>, std::map<std::string, std::string>>::serializedSize<false>(*prot_, this->otherMetadata);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t ResponseRpcMetadata::serializedSizeZC(Protocol_ const* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->serializedStructSize("ResponseRpcMetadata");
  if (this->__isset.protocol) {
    xfer += prot_->serializedFieldSize("protocol", apache::thrift::protocol::T_I32, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::ProtocolId>::serializedSize<false>(*prot_, this->protocol);
  }
  if (this->__isset.seqId) {
    xfer += prot_->serializedFieldSize("seqId", apache::thrift::protocol::T_I32, 2);
    xfer += prot_->serializedSizeI32(this->seqId);
  }
  if (this->__isset.otherMetadata) {
    xfer += prot_->serializedFieldSize("otherMetadata", apache::thrift::protocol::T_MAP, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::string>, std::map<std::string, std::string>>::serializedSize<false>(*prot_, this->otherMetadata);
  }
  xfer += prot_->serializedSizeStop();
  return xfer;
}

template <class Protocol_>
uint32_t ResponseRpcMetadata::write(Protocol_* prot_) const {
  uint32_t xfer = 0;
  xfer += prot_->writeStructBegin("ResponseRpcMetadata");
  if (this->__isset.protocol) {
    xfer += prot_->writeFieldBegin("protocol", apache::thrift::protocol::T_I32, 1);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::enumeration,  ::apache::thrift::ProtocolId>::write(*prot_, this->protocol);
    xfer += prot_->writeFieldEnd();
  }
  if (this->__isset.seqId) {
    xfer += prot_->writeFieldBegin("seqId", apache::thrift::protocol::T_I32, 2);
    xfer += prot_->writeI32(this->seqId);
    xfer += prot_->writeFieldEnd();
  }
  if (this->__isset.otherMetadata) {
    xfer += prot_->writeFieldBegin("otherMetadata", apache::thrift::protocol::T_MAP, 3);
    xfer += ::apache::thrift::detail::pm::protocol_methods< ::apache::thrift::type_class::map<::apache::thrift::type_class::string, ::apache::thrift::type_class::string>, std::map<std::string, std::string>>::write(*prot_, this->otherMetadata);
    xfer += prot_->writeFieldEnd();
  }
  xfer += prot_->writeFieldStop();
  xfer += prot_->writeStructEnd();
  return xfer;
}

}} // apache::thrift
