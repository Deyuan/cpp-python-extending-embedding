// A dummy C++ module
// Author: Deyuan Guo
// Date: March 13, 2019

#ifndef DUMMY_MODULE_H
#define DUMMY_MODULE_H

#include <string>

class dummyModule
{
  public:
    dummyModule() {}
    ~dummyModule() {}

    std::string process(const std::string &input);
};

#endif

