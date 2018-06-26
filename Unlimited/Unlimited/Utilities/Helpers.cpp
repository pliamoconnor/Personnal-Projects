#include "Helpers.h"

#include <iostream>
#include <stdio.h>

char* ReadFile(const char* filename, const char* readFormat)
{
	FILE* pFile = nullptr;			//File in memory that is being read
	long lsize = 0;					//Size of the file in bytes
	char* buffer = nullptr;			//Buffer of the data
	size_t result = 0;				//?

	//Open the file
	fopen_s(&pFile, filename, readFormat);
	if (pFile == nullptr)
	{
		std::cout << "Error opening file at: " + *filename << std::endl;
		return nullptr;
	}

	fseek(pFile, 0, SEEK_END);
	lsize = ftell(pFile);
	rewind(pFile);

	//allocate memory to contain the whole file
	buffer = new char[sizeof(char) * lsize];

	//copy the file into the buffer
	result = fread(buffer, 1, lsize, pFile);
	if (result != lsize)
	{
		std::cout << "Error reading reading string data from file at: " + *filename << std::endl;
		delete buffer;
		buffer = nullptr;
		return nullptr;
	}

	fclose(pFile);
	return buffer;
}

void WriteToFile(const char * filename, const char * fileContent)
{


}