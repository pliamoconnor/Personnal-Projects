#include "Common.h"

#include "Shader.h"

ShaderProgram::ShaderProgram(const char* vertexFileString, const char* fragmentFileString, const char* geometryFileString, const char* computeFileString, const char* additionalFileString)
{
	Initialize(vertexFileString, fragmentFileString, geometryFileString, computeFileString, additionalFileString);
}

ShaderProgram::~ShaderProgram()
{

}

void ShaderProgram::CleanUp()
{

}

GLuint ShaderProgram::CompileShader(GLenum shaderType, const char* shaderString, const char* additionalIncludes)
{
	if (additionalIncludes >= 0)
		shaderString += *additionalIncludes;



	return 1;
}

bool ShaderProgram::Initialize(const char* vertexFileString, const char* fragmentFileString, const char* geometryFileString, const char* computeFileString, const char* additionalFileString)
{


	return false;
}