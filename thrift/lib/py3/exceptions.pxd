from libcpp.string cimport string
from cpython.ref cimport PyObject
from folly cimport cFollyExceptionWrapper
from libcpp.memory cimport shared_ptr

cdef extern from * namespace "std":
    cdef cppclass cException "std:Exception":
        const char* what() nogil

cdef extern from "thrift/lib/cpp/Thrift.h" namespace "apache::thrift":
    cdef cppclass cTException "apache::thrift::TException"(cException):
        pass

    cdef cppclass cTLibraryException "apache::thrift::TLibraryException"(cTException):
        pass

cdef extern from "thrift/lib/cpp/TApplicationException.h" \
        namespace "apache::thrift":

    enum cTApplicationExceptionType "apache::thrift::TApplicationException::TApplicationExceptionType":
        cTApplicationExceptionType__UNKNOWN "apache::thrift::TApplicationException::UNKNOWN"
        cTApplicationExceptionType__UNKNOWN_METHOD "apache::thrift::TApplicationException::UNKNOWN_METHOD"
        cTApplicationExceptionType__INVALID_MESSAGE_TYPE "apache::thrift::TApplicationException::INVALID_MESSAGE_TYPE"
        cTApplicationExceptionType__WRONG_METHOD_NAME "apache::thrift::TApplicationException::WRONG_METHOD_NAME"
        cTApplicationExceptionType__BAD_SEQUENCE_ID "apache::thrift::TApplicationException::BAD_SEQUENCE_ID"
        cTApplicationExceptionType__MISSING_RESULT "apache::thrift::TApplicationException::MISSING_RESULT"
        cTApplicationExceptionType__INTERNAL_ERROR "apache::thrift::TApplicationException::INTERNAL_ERROR"
        cTApplicationExceptionType__PROTOCOL_ERROR "apache::thrift::TApplicationException::PROTOCOL_ERROR"
        cTApplicationExceptionType__INVALID_TRANSFORM "apache::thrift::TApplicationException::INVALID_TRANSFORM"
        cTApplicationExceptionType__INVALID_PROTOCOL "apache::thrift::TApplicationException::INVALID_PROTOCOL"
        cTApplicationExceptionType__UNSUPPORTED_CLIENT_TYPE "apache::thrift::TApplicationException::UNSUPPORTED_CLIENT_TYPE"
        cTApplicationExceptionType__LOADSHEDDING "apache::thrift::TApplicationException::LOADSHEDDING"
        cTApplicationExceptionType__TIMEOUT "apache::thrift::TApplicationException::TIMEOUT"
        cTApplicationExceptionType__INJECTED_FAILURE "apache::thrift::TApplicationException::INJECTED_FAILURE"

    cdef cppclass cTApplicationException \
            "apache::thrift::TApplicationException"(cTException):
        cTApplicationException(cTApplicationExceptionType type,
                               string& message) nogil except +
        cTApplicationExceptionType getType() nogil

cdef extern from "thrift/lib/cpp/transport/TTransportException.h" \
        namespace "apache::thrift::transport":

    enum cTTransportExceptionType "apache::thrift::transport::TTransportException::TTransportExceptionType":
        cTTransportExceptionType__UNKNOWN "apache::thrift::transport::TTransportException::UNKNOWN"
        cTTransportExceptionType__NOT_OPEN "apache::thrift::transport::TTransportException::NOT_OPEN"
        cTTransportExceptionType__ALREADY_OPEN "apache::thrift::transport::TTransportException::ALREADY_OPEN"
        cTTransportExceptionType__TIMED_OUT "apache::thrift::transport::TTransportException::TIMED_OUT"
        cTTransportExceptionType__END_OF_FILE "apache::thrift::transport::TTransportException::END_OF_FILE"
        cTTransportExceptionType__INTERRUPTED "apache::thrift::transport::TTransportException::INTERRUPTED"
        cTTransportExceptionType__BAD_ARGS "apache::thrift::transport::TTransportException::BAD_ARGS"
        cTTransportExceptionType__CORRUPTED_DATA "apache::thrift::transport::TTransportException::CORRUPTED_DATA"
        cTTransportExceptionType__INTERNAL_ERROR "apache::thrift::transport::TTransportException::INTERNAL_ERROR"
        cTTransportExceptionType__NOT_SUPPORTED "apache::thrift::transport::TTransportException::NOT_SUPPORTED"
        cTTransportExceptionType__INVALID_STATE "apache::thrift::transport::TTransportException::INVALID_STATE"
        cTTransportExceptionType__INVALID_FRAME_SIZE "apache::thrift::transport::TTransportException::INVALID_FRAME_SIZE"
        cTTransportExceptionType__SSL_ERROR "apache::thrift::transport::TTransportException::SSL_ERROR"
        cTTransportExceptionType__COULD_NOT_BIND "apache::thrift::transport::TTransportException::COULD_NOT_BIND"
        cTTransportExceptionType__SASL_HANDSHAKE_TIMEOUT "apache::thrift::transport::TTransportException::SASL_HANDSHAKE_TIMEOUT"
        cTTransportExceptionType__NETWORK_ERROR "apache::thrift::transport::TTransportException::NETWORK_ERROR"

    enum cTTransportExceptionOptions "apache::thrift::transport::TTransportException::Options":
        cTTransportExceptionOptions__CHANNEL_IS_VALID "apache::thrift::transport::TTransportException::CHANNEL_IS_VALID"

    cdef cppclass cTTransportException "apache::thrift::transport::TTransportException"(cTLibraryException):
        ## No need to instance from Python
        int getOptions()
        cTTransportExceptionType getType()
        int getErrno()

cdef extern from "Python.h":
    ctypedef extern class builtins.Exception[object PyBaseExceptionObject]:
        pass


cdef extern from "thrift/lib/py3/exceptions.h" namespace "thrift::py3::exception":
    cdef shared_ptr[T] try_make_shared_exception[T](
        const cFollyExceptionWrapper& excepton)


ctypedef void(*Handler)(const cFollyExceptionWrapper& ex) except *
cdef void addHandler(Handler handler)
cdef void runHandlers(const cFollyExceptionWrapper& ex) except *
cdef raise_py_exception(const cFollyExceptionWrapper& ex)

# cdef Inheritence sucks in cython
cdef create_Error(shared_ptr[cTException] ex)
cdef create_ApplicationError(shared_ptr[cTApplicationException] ex)
cdef create_LibraryError(shared_ptr[cTLibraryException] ex)
cdef create_TransportError(shared_ptr[cTTransportException] ex)


cdef class Error(Exception):
    pass

cdef class LibraryError(Error):
    pass

cdef class ApplicationError(Error):
    pass

cdef class TransportError(LibraryError):
    pass
