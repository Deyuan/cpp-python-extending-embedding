// Embed and Extend Python
// Author: Deyuan Guo
// Date: March 13, 2019

#include <Python.h>
#include "dummy_module.h"

// Extend: Python calling C++ code
PyObject * hello_world(PyObject * self, PyObject * args) {
  const char * arg = NULL;
  if (!PyArg_ParseTuple(args, "s", &arg)) {
    Py_DECREF(args);
    return NULL;
  }

  // C++
  dummyModule module;
  std::string input = arg;
  std::string output = module.process(input);

  PyObject *retVal = Py_BuildValue("s", output.c_str());
  Py_DECREF(args);
  return retVal;
}

// Extend: Python methed definition
PyMethodDef myPyMethods[] = {
  {"hello_world", hello_world, METH_VARARGS, "A hello-world function"},
  {NULL, NULL, 0, NULL}
};

// Extend: Python module definition
PyModuleDef myPyModule = {
  PyModuleDef_HEAD_INIT,
  "hello",
  NULL, -1,
  myPyMethods,
  NULL, NULL, NULL, NULL
};

// Extend: Python module init function
PyMODINIT_FUNC PyInit_hello() {
  return PyModule_Create(&myPyModule);
}

// Embed: Set program name as argv[0]
void myPySetProgramName(const char * program) {
  wchar_t *prog = Py_DecodeLocale(program, NULL);
  if (prog == NULL) {
    fprintf(stderr, "Error: Cannot decode argv[0]\n");
  }
  Py_SetProgramName(prog);
}

// Embed: Initialize embedded Python
void myPyInitialize() {
  // Extend with hello module
  PyImport_AppendInittab("hello", &PyInit_hello);
  Py_Initialize();
}

// Embed: Finalize embedded Python
void myPyFinalize() {
  Py_Finalize();
}

// Embed: Run a Python string
void myPyRunSimpleString(const char * str) {
  PyRun_SimpleString(str);
}

// Embed: Run interactive Python shell
void myPyRunInteractive() {
  PyRun_InteractiveLoop(stdin, "<stdin>");
}

// Embed: Run a Python script file
void myPyRunSimpleFile(const char * filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error: Cannot open file %s\n", filename);
  } else {
    PyRun_SimpleFile(fp, filename);
    fclose(fp);
  }
}

