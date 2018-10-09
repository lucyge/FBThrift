/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/types/gen-cpp/SomeService.h"
#include <folly/ScopeGuard.h>

#include "thrift/compiler/test/fixtures/types/gen-cpp/module_reflection.h"

namespace apache { namespace thrift { namespace fixtures { namespace types {

const uint64_t SomeService_bounce_map_args::_reflection_id;
void SomeService_bounce_map_args::_reflection_register(::apache::thrift::reflection::Schema& schema) {
   ::apache::thrift::fixtures::types::module_reflection_::reflectionInitializer_8067468913239303596(schema);
}

void SomeService_bounce_map_args::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "m") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_MAP;
  }
};

uint32_t SomeService_bounce_map_args::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string _fname;
  apache::thrift::protocol::TType _ftype;
  int16_t fid;

  ::apache::thrift::reflection::Schema * schema = iprot->getSchema();
  if (schema != nullptr) {
     ::apache::thrift::fixtures::types::module_reflection_::reflectionInitializer_8067468913239303596(*schema);
    iprot->setNextStructType(SomeService_bounce_map_args::_reflection_id);
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
        if (_ftype == apache::thrift::protocol::T_MAP) {
          {
            this->m.clear();
            uint32_t _size86;
            bool _sizeUnknown87;
            apache::thrift::protocol::TType _ktype88 = apache::thrift::protocol::T_STOP;
            apache::thrift::protocol::TType _vtype89 = apache::thrift::protocol::T_STOP;
            xfer += iprot->readMapBegin(_ktype88, _vtype89, _size86, _sizeUnknown87);
            if (!_sizeUnknown87) {
              uint32_t _i92;
              for (_i92 = 0; _i92 < _size86; ++_i92)
              {
                int32_t _key93;
                xfer += iprot->readI32(_key93);
                std::string& _val94 = this->m[_key93];
                xfer += iprot->readString(_val94);
              }
            } else {
              while (iprot->peekMap())
              {
                int32_t _key95;
                xfer += iprot->readI32(_key95);
                std::string& _val96 = this->m[_key95];
                xfer += iprot->readString(_val96);
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.m = true;
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

uint32_t SomeService_bounce_map_args::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("SomeService_bounce_map_args");
  xfer += oprot->writeFieldBegin("m", apache::thrift::protocol::T_MAP, 1);
  {
    xfer += oprot->writeMapBegin(apache::thrift::protocol::T_I32, apache::thrift::protocol::T_STRING, this->m.size());
    std::unordered_map<int32_t, std::string> ::const_iterator _iter97;
    for (_iter97 = this->m.begin(); _iter97 != this->m.end(); ++_iter97)
    {
      xfer += oprot->writeI32(_iter97->first);
      xfer += oprot->writeString(_iter97->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const uint64_t SomeService_bounce_map_pargs::_reflection_id;
void SomeService_bounce_map_pargs::_reflection_register(::apache::thrift::reflection::Schema& schema) {
   ::apache::thrift::fixtures::types::module_reflection_::reflectionInitializer_13692909882459418892(schema);
}

void SomeService_bounce_map_pargs::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "m") {
    fid = 1;
    _ftype = apache::thrift::protocol::T_MAP;
  }
};

uint32_t SomeService_bounce_map_pargs::write(apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("SomeService_bounce_map_pargs");
  xfer += oprot->writeFieldBegin("m", apache::thrift::protocol::T_MAP, 1);
  {
    xfer += oprot->writeMapBegin(apache::thrift::protocol::T_I32, apache::thrift::protocol::T_STRING, (*(this->m)).size());
    std::unordered_map<int32_t, std::string> ::const_iterator _iter98;
    for (_iter98 = (*(this->m)).begin(); _iter98 != (*(this->m)).end(); ++_iter98)
    {
      xfer += oprot->writeI32(_iter98->first);
      xfer += oprot->writeString(_iter98->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const uint64_t SomeService_bounce_map_presult::_reflection_id;
void SomeService_bounce_map_presult::_reflection_register(::apache::thrift::reflection::Schema& schema) {
   ::apache::thrift::fixtures::types::module_reflection_::reflectionInitializer_14908807508243143308(schema);
}

void SomeService_bounce_map_presult::translateFieldName(
    FOLLY_MAYBE_UNUSED folly::StringPiece _fname,
    FOLLY_MAYBE_UNUSED int16_t& fid,
    FOLLY_MAYBE_UNUSED apache::thrift::protocol::TType& _ftype) {
  if (false) {}
  else if (_fname == "success") {
    fid = 0;
    _ftype = apache::thrift::protocol::T_MAP;
  }
};

uint32_t SomeService_bounce_map_presult::read(apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string _fname;
  apache::thrift::protocol::TType _ftype;
  int16_t fid;

  ::apache::thrift::reflection::Schema * schema = iprot->getSchema();
  if (schema != nullptr) {
     ::apache::thrift::fixtures::types::module_reflection_::reflectionInitializer_14908807508243143308(*schema);
    iprot->setNextStructType(SomeService_bounce_map_presult::_reflection_id);
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
      case 0:
        if (_ftype == apache::thrift::protocol::T_MAP) {
          {
            (*(this->success)).clear();
            uint32_t _size99;
            bool _sizeUnknown100;
            apache::thrift::protocol::TType _ktype101 = apache::thrift::protocol::T_STOP;
            apache::thrift::protocol::TType _vtype102 = apache::thrift::protocol::T_STOP;
            xfer += iprot->readMapBegin(_ktype101, _vtype102, _size99, _sizeUnknown100);
            if (!_sizeUnknown100) {
              uint32_t _i105;
              for (_i105 = 0; _i105 < _size99; ++_i105)
              {
                int32_t _key106;
                xfer += iprot->readI32(_key106);
                std::string& _val107 = (*(this->success))[_key106];
                xfer += iprot->readString(_val107);
              }
            } else {
              while (iprot->peekMap())
              {
                int32_t _key108;
                xfer += iprot->readI32(_key108);
                std::string& _val109 = (*(this->success))[_key108];
                xfer += iprot->readString(_val109);
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.success = true;
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

uint32_t SomeService_bounce_map_presult::write(apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("SomeService_bounce_map_presult");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", apache::thrift::protocol::T_MAP, 0);
    {
      xfer += oprot->writeMapBegin(apache::thrift::protocol::T_I32, apache::thrift::protocol::T_STRING, (*(this->success)).size());
      std::unordered_map<int32_t, std::string> ::const_iterator _iter110;
      for (_iter110 = (*(this->success)).begin(); _iter110 != (*(this->success)).end(); ++_iter110)
      {
        xfer += oprot->writeI32(_iter110->first);
        xfer += oprot->writeString(_iter110->second);
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

int32_t SomeServiceClient::getNextSendSequenceId()
{
  return nextSendSequenceId_++;
}

int32_t SomeServiceClient::getNextRecvSequenceId()
{
  return nextRecvSequenceId_++;
}

const char* SomeServiceClient::getServiceName() {
{
  return "SomeService";
}
}
void SomeServiceClient::bounce_map( ::apache::thrift::fixtures::types::SomeMap& _return, const  ::apache::thrift::fixtures::types::SomeMap& m)
{
  SCOPE_EXIT { this->clearClientContextStack(); };
  this->generateClientContextStack(this->getServiceName(), "SomeService.bounce_map", this->getConnectionContext());

  try {
    send_bounce_map(m);
    recv_bounce_map(_return);
  } catch (apache::thrift::transport::TTransportException&) {
    ::apache::thrift::ContextStack* c = this->getClientContextStack();
    if (c) c->handlerError();
    iprot_->getTransport()->close();
    oprot_->getTransport()->close();
    throw;
  } catch (apache::thrift::TApplicationException& ex) {
    if (ex.getType() == apache::thrift::TApplicationException::BAD_SEQUENCE_ID) {
      ::apache::thrift::ContextStack* c = this->getClientContextStack();
      if (c) c->handlerError();
      iprot_->getTransport()->close();
      oprot_->getTransport()->close();
    }
    throw;
  }
}

void SomeServiceClient::send_bounce_map(const  ::apache::thrift::fixtures::types::SomeMap& m)
{
  apache::thrift::ContextStack* ctx = this->getClientContextStack();
  if (ctx) ctx->preWrite();
  oprot_->writeMessageBegin("bounce_map", apache::thrift::protocol::T_CALL, getNextSendSequenceId());

  SomeService_bounce_map_pargs args;
  args.m = &m;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  uint32_t _bytes111 = oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
  if (ctx) ctx->postWrite(_bytes111);
  return;
}

folly::exception_wrapper SomeServiceClient::recv_wrapped_bounce_map( ::apache::thrift::fixtures::types::SomeMap& _return)
{
  apache::thrift::ContextStack* ctx = this->getClientContextStack();
  int32_t rseqid = 0;
  int32_t eseqid = getNextRecvSequenceId();
  std::string _fname;
  apache::thrift::protocol::TMessageType mtype;
  if (ctx) ctx->preRead();
  folly::exception_wrapper interior_ew;
  auto caught_ew = folly::try_and_catch<apache::thrift::TException, apache::thrift::protocol::TProtocolException>([&]() {
    iprot_->readMessageBegin(_fname, mtype, rseqid);
    if (this->checkSeqid_ && rseqid != eseqid) {
      iprot_->skip(apache::thrift::protocol::T_STRUCT);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::BAD_SEQUENCE_ID);
      return; // from try_and_catch
    }
    if (mtype == apache::thrift::protocol::T_EXCEPTION) {
      apache::thrift::TApplicationException x;
      x.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(x);
      return; // from try_and_catch
    }
    if (mtype != apache::thrift::protocol::T_REPLY) {
      iprot_->skip(apache::thrift::protocol::T_STRUCT);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::INVALID_MESSAGE_TYPE);
      return; // from try_and_catch
    }
    if (_fname.compare("bounce_map") != 0) {
      iprot_->skip(apache::thrift::protocol::T_STRUCT);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();
      interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::WRONG_METHOD_NAME);
      return; // from try_and_catch
    }
    SomeService_bounce_map_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    uint32_t bytes = iprot_->getTransport()->readEnd();
    if (ctx) ctx->postRead(nullptr, bytes);
    if (result.__isset.success) {
      // _return pointer has now been filled
      return; // from try_and_catch
    }
    interior_ew = folly::make_exception_wrapper<apache::thrift::TApplicationException>(apache::thrift::TApplicationException::MISSING_RESULT, "bounce_map failed: unknown result");
    return; // from try_and_catch
  });
  if (interior_ew || caught_ew) {
    return interior_ew ? interior_ew : caught_ew;
  }
  return folly::exception_wrapper();
}

void SomeServiceClient::recv_bounce_map( ::apache::thrift::fixtures::types::SomeMap& _return)
{
  auto ew = recv_wrapped_bounce_map(_return);
  if (ew) {
    ew.throw_exception();
  }
}

bool SomeServiceProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& _fname, int32_t seqid, apache::thrift::server::TConnectionContext* connectionContext) {
  ProcessMap::iterator pfn;
  pfn = processMap_.find(_fname);
  if (pfn == processMap_.end()) {
    iprot->skip(apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    apache::thrift::TApplicationException x(apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+_fname+"'");
    oprot->writeMessageBegin(_fname, apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return true;
  }
  const ProcessFunction& pf = pfn->second;
  (this->*pf)(seqid, iprot, oprot, connectionContext);
  return true;
}

void SomeServiceProcessor::process_bounce_map(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, apache::thrift::server::TConnectionContext* connectionContext)
{
  std::unique_ptr<apache::thrift::ContextStack> ctx(this->getContextStack(this->getServiceName(), "SomeService.bounce_map", connectionContext));

  if (ctx) ctx->preRead();
  SomeService_bounce_map_args args;
  try {
    args.read(iprot);
  } catch (const apache::thrift::protocol::TProtocolException& e) {
    apache::thrift::TApplicationException x(apache::thrift::TApplicationException::PROTOCOL_ERROR, e.what());
    oprot->writeMessageBegin("bounce_map", apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (ctx) ctx->postRead(nullptr, bytes);

  SomeService_bounce_map_presult result;
   ::apache::thrift::fixtures::types::SomeMap success;
  result.success = &success;
  try {
    iface_->bounce_map(*result.success, args.m);
    result.__isset.success = true;
  } catch (const std::exception& e) {
    if (ctx) ctx->handlerError();


    apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("bounce_map", apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (ctx) ctx->preWrite();
  oprot->writeMessageBegin("bounce_map", apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (ctx) ctx->postWrite(bytes);

}

::std::shared_ptr< ::apache::thrift::TProcessor > SomeServiceProcessorFactory::getProcessor(::apache::thrift::server::TConnectionContext* ctx) {
  ::apache::thrift::ReleaseHandler< SomeServiceIfFactory > cleanup(handlerFactory_);
  ::std::shared_ptr< SomeServiceIf > handler(handlerFactory_->getHandler(ctx), cleanup);
  ::std::shared_ptr< ::apache::thrift::TProcessor > processor(new SomeServiceProcessor(handler));
  return processor;
}
}}}} // namespace

