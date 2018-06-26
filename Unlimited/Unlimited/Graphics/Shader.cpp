#include "Common.h"

#include "Shader.h"

ShaderProgram::ShaderProgram(const char* vertexFileString, const char* fragmentFileString, const char* geometryFileString, const char* computeFileString, const char* additionalFileString)
{
	Initialize(vertexFileString, fragmentFileString, geometryFileString, computeFileString, additionalFileString);
}

ShaderProgram::~ShaderProgram()
{
	CleanUp();
}

void ShaderProgram::CleanUp()
{
	//TODO: Clean up all of the shader program class data here pleaze
}

unsigned int ShaderProgram::CreateShader(GLenum shaderType, const char* shaderString, const char* additionalIncludes)
{
	//If their are any additional includes then take them in here
	if (additionalIncludes >= 0)
		shaderString += *additionalIncludes;

	//Create a shader
	unsigned int shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderString, NULL);
	glCompileShader(shader);

	//Error checking to make sure that the shader was compiled properly

	int result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(shader, length, &length, message);

		printf("Failed to compile shader. Error: " + *message);
		glDeleteShader(shader);
		assert(false);
	}

	return shader;
}

bool ShaderProgram::Initialize(const char* vertexFileString, const char* fragmentFileString, const char* geometryFileString, const char* computeFileString, const char* additionalFileString)
{
	m_Program = glCreateProgram();

	if (vertexFileString == nullptr)
		assert(false);
	if (fragmentFileString == nullptr)
		assert(false);

	if (additionalFileString != nullptr)
		m_AdditionalIncludes = ReadFile(additionalFileString);

	m_VertexShaderString = ReadFile(vertexFileString);
	CreateShader(GL_VERTEX_SHADER, m_VertexShaderString);
	
	m_FragmentShaderString = ReadFile(fragmentFileString);
	CreateShader(GL_FRAGMENT_SHADER, m_FragmentShaderString);

	if (geometryFileString != nullptr)
		m_GeometryShaderString = ReadFile(geometryFileString);

	if (computeFileString != nullptr)
		m_ComputeShaderString = ReadFile(computeFileString);



	return false;
}