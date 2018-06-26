#include "Graphics\Graphics.h"
#include <iostream>

#define ASSERT(flag) if(!flag) __debugbreak();
#define GLSafeCall(x) GLClearErrors(); x; ASSERT(GLCheckForErrors(#x, __FILE__, __LINE__))


bool GLCheckForErrors(const char* function, const char* file, const char* line)
{
	GLenum result = glGetError();

	if (result != 0)
	{
		std::cout << "OpenGL error detected (" << GLEnumToString(result) << ")" <<
			" " << function << " " << file << ": " << line << std::endl;

		return false;
	}

	return true;
}

void GLClearErrors()
{
	while (glGetError() != GL_NO_ERROR);
}

const char* GLEnumToString(GLenum enumValue)
{
	switch (enumValue)
	{
	case GL_NO_ERROR:
		return "GL_NO_ERROR";
		
	case GL_INVALID_ENUM:
		return "GL_INVALID_ENUM";

	case GL_INVALID_VALUE:
		return "GL_INVALID_VALUE";

	case GL_INVALID_OPERATION:
		return "GL_INVALID_OPERATION";

	case GL_INVALID_FRAMEBUFFER_OPERATION:
		return "GL_INVALID_FRAMEBUFFER_OPERATION";

	case GL_OUT_OF_MEMORY:
		return "GL_OUT_OF_MEMORY";

	case GL_STACK_UNDERFLOW:
		return "GL_STACK_UNDERFLOW";

	case GL_STACK_OVERFLOW:
		return "GL_STACK_OVERFLOW";

	default:
		return nullptr;

	}
}