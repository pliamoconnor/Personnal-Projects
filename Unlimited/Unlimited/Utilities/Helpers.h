#ifndef HELPERS_H
#define HELPERS_H

//Reads a file at the location "filename" and dynamically allocates the data from the file.
char* ReadFile(const char* filename, const char* readFormat = "rb");

//Writes the data in fileContent to a file. The directory of the file should be included in filename.
void WriteToFile(const char* filename, const char* fileContent);

#endif
