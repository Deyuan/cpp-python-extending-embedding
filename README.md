# cpp-python-extending-embedding
Prototyping: Embed Python in C++ and extend Python to call C++ modules simultaneously

## Description
The code demonstrates how to embed Python into C++ and how to extend Python with C++ simultaneously
* Embedding: Calling Python interpreter from C++
* Extending: Calling a C++ module from Python

## Notes
* Reference: https://docs.python.org/3/extending/embedding.html
* This demo uses anaconda3 and uses python-config to generate compiler flags
* Not every Python package can be imported to embedded Python, and they may cause crashes

## Output
```./demo.out
Entering embedded Python
C++ Main: Passing string to embedded Python: Embed and Extend
Python: Passing string to C++ module: Embed and Extend
C++ Module: Received string from embedded Python: Embed and Extend
Python: Result: OK
Exiting embedded Python
```
