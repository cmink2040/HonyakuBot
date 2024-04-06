#ifndef AICTL_H
#define AICTL_H

#include <iostream>
#include <string>
#include <Python.h>

#include <cstdio>   // For popen(), pclose()
#include <cstring>  // For strerror()

#include <cstdlib> 

#include <vector>


std::string executePythonScript(std::string venvdir, std::string pydir, std::vector<std::string> args);

std::string aictl(std::string venvdir, std::string pythonfile, std::string pypath, std::vector<std::string> storage);

#endif  