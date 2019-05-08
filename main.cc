// Main
// Author: Deyuan Guo
// Date: March 13, 2019

#include <iostream>
#include "embed_and_extend.h"

int main(int argc, char *argv[])
{
  std::cout << "Entering embedded Python" << std::endl;

  myPySetProgramName(argv[0]);

  myPyInitialize();

  // C++ -> Python -> C++
  std::string message = "Embed and Extend";
  std::cout << "C++ Main: Passing string to embedded Python: " << message << std::endl;

  std::string pyCmd = "import hello\n";
  pyCmd += "message = '" + message + "'\n";
  pyCmd += "print('Python: Passing string to C++ module:', message)\n";
  pyCmd += "result = hello.hello_world(message)\n";
  pyCmd += "print('Python: Result:', result)\n";

  myPyRunSimpleString(pyCmd.c_str());

  // Run interactive Python shell
  // myPyRunInteractive();

  myPyFinalize();

  std::cout << "Exiting embedded Python" << std::endl;

  return 0;
}

