#include <iostream>
#include <string>
#include <Python.h>

#include <cstdio>   // For popen(), pclose()
#include <cstring>  // For strerror()

#include <cstdlib>  // For system() function

#include <vector>


std::string executePythonScript(std::string venvdir, std::string pydir, std::vector<std::string> args) {
    std::string response;

    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pResult;

    system(venvdir.c_str());
    Py_Initialize();
    

    // "/home/cmink/Documents/Source/HonyakuBot/venv/bin/activate"
    // "/home/cmink/Documents/Source/HonyakuBot/app/main.py"
    pName = PyUnicode_DecodeFSDefault(pydir.c_str());
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        // Get the reference to the function within the Python module
        pFunc = PyObject_GetAttrString(pModule, "main");

        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(args.size());

            for (int i = 0; i < args.size(); i++) {
                PyTuple_SetItem(pArgs, i, PyUnicode_FromString(args.at(i).c_str() ));
            }

            pResult = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pResult != NULL) {
                // Convert the Python result to a C string
                response = PyUnicode_AsUTF8(pResult);
                Py_DECREF(pResult);
            } else {
                PyErr_Print();
                std::cerr << "Failed to execute Python function." << std::endl;
            }
        } else {
            if (PyErr_Occurred())
                PyErr_Print();
            std::cerr << "Cannot find Python function 'my_function'." << std::endl;
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
        std::cerr << "Failed to load Python module 'main.py'." << std::endl;
    }

    // Finalize Python interpreter
    Py_Finalize();


    return response;
}



std::string aictl(std::string venvdir, std::string pythonfile, std::string pypath, std::vector<std::string> storage) {
    setenv("PYTHONPATH",pypath.c_str(), 1);
    return executePythonScript(venvdir, pythonfile, storage);
}

int main() {

    std::vector<std::string> storage;
    storage.push_back("n");
    storage.push_back("c");
    storage.push_back("cafa");
    storage.push_back("caffas");

    std::cout << aictl("/home/cmink/Documents/Source/HonyakuBot/venv/bin/activate", "ai","../app", storage) << std::endl;
    return 0;
}
