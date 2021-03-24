#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject * fastgauss_quickermaths(PyObject *self, PyObject *args)
{
    const long n;
    if (!PyArg_ParseTuple(args, "i", &n)) {
        return NULL;
    }
    return PyLong_FromLong((n*(n-1))/2);
}

static PyMethodDef fastgaussMethods[] = {
    
    {"quickermaths",  fastgauss_quickermaths, METH_VARARGS,
     "Gauss"},
    
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


static struct PyModuleDef fastgaussmodule = {
    PyModuleDef_HEAD_INIT,
    "lelc",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
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

    /* Add a built-in module, before Py_Initialize */
    if (PyImport_AppendInittab("fastgaussmodule", PyInit_fastgaussmodule) == -1) {
        fprintf(stderr, "Error: could not extend in-built modules table\n");
        exit(1);
    }

    /* Pass argv[0] to the Python interpreter */
    Py_SetProgramName(program);

    /* Initialize the Python interpreter.  Required.
       If this step fails, it will be a fatal error. */
    Py_Initialize();

    /* Optionally import the module; alternatively,
       import can be deferred until the embedded script
       imports it. */
    
    if (!PyImport_ImportModule("fastgaussmodule")) {
        PyErr_Print();
        fprintf(stderr, "Error: could not import module 'fastgaussmodule'\n");
    }

    

    PyMem_RawFree(program);
    return 0;
}