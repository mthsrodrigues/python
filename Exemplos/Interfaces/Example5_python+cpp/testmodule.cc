#include <Python.h>
#include <iostream>

// Função que será chamada do Python
static PyObject* testSrc(PyObject* self, PyObject* args) {
    const char* name;
    
    // Parseia argumentos: espera uma string
    if (!PyArg_ParseTuple(args, "s", &name))
        return NULL;
    
    // Faz algo com o argumento
    std::cout << "Hello from C++: " << name << std::endl;
    
    // Retorna None (não retorna valor)
    Py_RETURN_NONE;
}

// Tabela de métodos do módulo
static PyMethodDef MyMethods[] = {
    {"my_test", testSrc, METH_VARARGS, "Print a greeting."},
    {NULL, NULL, 0, NULL}  // Sentinela
};

// Definição do módulo
static struct PyModuleDef MyModule = {
    PyModuleDef_HEAD_INIT,
    "MyModule",           // Nome do módulo
    NULL,                 // Documentação
    -1,                   // Tamanho do estado
    MyMethods             // Métodos
};

// Função de inicialização - NOME DEVE SER "init" + NomeDoModulo
PyMODINIT_FUNC PyInit_MyModule(void) {
    return PyModule_Create(&MyModule);
}
