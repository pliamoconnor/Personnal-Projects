#ifndef GRAPHICS_INCLUDES
#define GRAPHICS_INCLUDES

#include <GL\glew.h>
#include <GLFW\glfw3.h>

//Check for GLErrors and have them outputed to the consol and output log.
//This function will also return the error that poped up.
bool GLCheckForErrors(const char* function, const char* file, const char* line);

//This function should be called at the end of a frame in order to clear all of the pending errors that
//OpenGL may have pending from the previous frame.
void GLClearErrors();

//Converts certain GLEnum types to an equivilant string
const char* GLEnumToString(GLenum enumValue);


#endif
