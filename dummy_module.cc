// A dummy C++ module
// Author: Deyuan Guo
// Date: March 13, 2019

#include "dummy_module.h"
#include <iostream>

std::string
dummyModule::process(const std::string &input)
{
  std::cout << "C++ Module: Received string from embedded Python: " << input << std::endl;
  return "OK";
}

