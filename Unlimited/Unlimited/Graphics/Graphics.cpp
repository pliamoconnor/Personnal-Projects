#include "Graphics\Graphics.h"

unsigned int GLCheckForErrors()
{
	unsigned int result = glGetError();

	if (result != 0)
	{
		
	}

	return -1;
}

void GLClearErrors()
{
	int result = 0;

	do
	{
		result = GLCheckForErrors();
	} while (result != 0);
}