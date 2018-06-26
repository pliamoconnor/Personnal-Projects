#ifndef HELPERS_H
#define HELPERS_H

//Reads a file at the location "filename" and dynamically allocates the data from the file.
char* ReadFile(const char* filename, const char* readFormat = "rb");

#endif
