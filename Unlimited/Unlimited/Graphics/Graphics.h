#ifndef GRAPHICS_INCLUDES
#define GRAPHICS_INCLUDES

#include <GL\glew.h>
#include <GLFW\glfw3.h>

static bool glAssertAllErrors = false;

//Check for GLErrors and have them outputed to the consol and output log.
//This function will also return the error that poped up.
unsigned int GLCheckForErrors();

//This function should be called at the end of a frame in order to clear all of the pending errors that
//OpenGL may have pending from the previous frame.
void GLClearErrors();

#endif
