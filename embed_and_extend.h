// Embed and Extend Python
// Author: Deyuan Guo
// Date: March 13, 2019

#ifndef EMBED_AND_EXTEND_H
#define EMBED_AND_EXTEND_H

void myPySetProgramName(const char * program);
void myPyInitialize();
void myPyFinalize();
void myPyRunSimpleString(const char * str);
void myPyRunInteractive();
void myPyRunSimpleFile(const char * filename);

#endif

