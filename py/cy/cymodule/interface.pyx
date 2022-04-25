# distutils: language = c++

cdef extern from "add.h":
  cpdef int add()
