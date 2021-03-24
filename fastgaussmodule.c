#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject * fastgauss_quickermaths(PyObject *self, PyObject *args)
{
    const long n;
    if (!PyArg_ParseTuple(args, "i", &n)) {
        return NULL;
    }
    return PyLong_FromLong((n*(n+1))/2);
}

static PyMethodDef fastgaussMethods[] = {
    
    {"quickermaths",  fastgauss_quickermaths, METH_VARARGS,
     "Gauss"},
    
    {NULL, NULL, 0, NULL}        
};


static struct PyModuleDef fastgaussmodule = {
    PyModuleDef_HEAD_INIT,
    "fastgaussmodule",   
    NULL, 
    -1,
    fastgaussMethods
};

PyMODINIT_FUNC
PyInit_fastgaussmodule(void)
{
    return PyModule_Create(&fastgaussmodule);
}


int
main(int argc, char *argv[])
{
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }

    
    if (PyImport_AppendInittab("fastgaussmodule", PyInit_fastgaussmodule) == -1) {
        fprintf(stderr, "Error: could not extend in-built modules table\n");
        exit(1);
    }

   
    Py_SetProgramName(program);

   
    Py_Initialize();

    
    
    if (!PyImport_ImportModule("fastgaussmodule")) {
        PyErr_Print();
        fprintf(stderr, "Error: could not import module 'fastgaussmodule'\n");
    }

    

    PyMem_RawFree(program);
    return 0;
}