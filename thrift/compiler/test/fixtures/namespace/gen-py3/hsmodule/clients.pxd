#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
from libcpp.memory cimport shared_ptr
cimport thrift.py3.client


from hsmodule.clients_wrapper cimport cHsTestServiceClientWrapper

cdef class HsTestService(thrift.py3.client.Client):
    cdef shared_ptr[cHsTestServiceClientWrapper] _hsmodule_HsTestService_client

    @staticmethod
    cdef _hsmodule_HsTestService_set_client(HsTestService inst, shared_ptr[cHsTestServiceClientWrapper] c_obj)

    cdef _hsmodule_HsTestService_reset_client(HsTestService self)

