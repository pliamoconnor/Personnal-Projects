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
	glDetachShader(m_Program, m_VertexShader);
	glDeleteShader(m_VertexShader);

	glDetachShader(m_Program, m_FragmentShader);
	glDeleteShader(m_FragmentShader);

	if (m_ComputeShader != -1)
	{
		glDetachShader(m_Program, m_ComputeShader);
		glDeleteShader(m_ComputeShader);
	}

	if (m_GeometryShader != -1)
	{
		glDetachShader(m_Program, m_GeometryShader);
		glDeleteShader(m_GeometryShader);
	}

	glDeleteProgram(m_Program);


	if (m_AdditionalIncludes != nullptr)
	{
		delete m_AdditionalIncludes;
		m_AdditionalIncludes = nullptr;
	}

	if (m_VertexShaderString != nullptr)
	{
		delete m_VertexShaderString;
		m_VertexShaderString = nullptr;
	}

	if (m_FragmentShaderString != nullptr)
	{
		delete m_FragmentShaderString;
		m_FragmentShaderString = nullptr;
	}

	if (m_ComputeShaderString != nullptr)
	{
		delete m_ComputeShaderString;
		m_ComputeShaderString = nullptr;
	}

	if (m_GeometryShaderString != nullptr)
	{
		delete m_GeometryShaderString;
		m_GeometryShaderString = nullptr;
	}
}

unsigned int ShaderProgram::CreateShader(unsigned int shaderType, const char* shaderString, const char* additionalIncludes)
{
	//If their are any additional includes then take them in here
	char* fullShaderString = const_cast<char*>(shaderString);
	if (additionalIncludes >= 0)
		*fullShaderString += *additionalIncludes;

	//Create a shader
	unsigned int shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &fullShaderString, NULL);
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
	m_VertexShader = CreateShader(GL_VERTEX_SHADER, m_VertexShaderString, m_AdditionalIncludes);

	m_FragmentShaderString = ReadFile(fragmentFileString);
	m_FragmentShader = CreateShader(GL_FRAGMENT_SHADER, m_FragmentShaderString, m_AdditionalIncludes);

	if (geometryFileString != nullptr)
	{
		m_GeometryShaderString = ReadFile(geometryFileString);
		m_GeometryShader = CreateShader(GL_GEOMETRY_SHADER, m_GeometryShaderString, m_AdditionalIncludes);
	}

	if (computeFileString != nullptr)
	{
		m_ComputeShaderString = ReadFile(computeFileString);
		m_ComputeShader = CreateShader(GL_COMPUTE_SHADER, m_ComputeShaderString, m_AdditionalIncludes);
	}


	return false;
}