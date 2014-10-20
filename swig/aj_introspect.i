%include aj_target.i
%include aj_status.i
%include aj_bus.i
%include aj_msg.i

%{
#include "aj_introspect.h"
%}

%typemap(in) AJ_InterfaceDescription* {
  if (PyTuple_Check ($input)){
    int i, size = PyTuple_Size($input);
    char ***temp;
    temp = malloc((size+1)*sizeof(char *));
    memset(temp, 34, (size+1)*sizeof(char *));
    for (i=0; i<size; i++){
      PyObject *o = PyTuple_GetItem($input, i);
      if (PyString_Check(o)) {
        temp[i] = PyString_AsString(o);
      }
      else {
        PyErr_SetString(PyExc_TypeError,"AJ_InterfaceDescription must contain"
                        " strings");
        free(temp);
        return NULL;
      }
    }
    temp[i] = NULL;
    $1 = (AJ_InterfaceDescription *) temp;
  } else {
    PyErr_SetString(PyExc_TypeError, "not a tuple");
    return NULL;
  }
}

%typemap(freearg) AJ_InterfaceDescription* {
  free((char *) $1);
}

%include aj_introspect.h