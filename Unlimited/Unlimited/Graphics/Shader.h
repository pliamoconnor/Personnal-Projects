#ifndef SHADER_H
#define SHADER_H

class ShaderProgram
{
public:
	ShaderProgram(const char* vertexFileString, const char* fragmentFileString, const char* geometryFileString = 0, const char* computeFileString = 0, const char* additionalFileString = 0);
	~ShaderProgram();

	//Cleans up the shader program's allocated memory
	void CleanUp();

	//Compiles the shaders from strings into shader objects
	GLuint CompileShader(GLenum shaderType, const char* shaderString, const char* additionalIncludes = 0);

	bool Initialize(const char* vertexFileString, const char* fragmentFileString, const char* geometryFileString = 0, const char* computeFileString = 0, const char* additionalFileString = 0);

	//The program object related to this shader
	GLuint GetProgram() { return m_Program; }

private:
	//Holds the vertex shader as a string
	char* m_VertexShaderString;
	//Holds the geometry shader as a string
	char* m_GeometryShaderString;
	//Holds the fragment shader as a string
	char* m_FragmentShaderString;
	//Holds the compute shader as a string
	char* m_ComputeShaderString;

	//Holds any additional includes that a shader may need
	char* m_AdditionalIncludes;

	//Buffer that holds the vertex shader
	GLuint m_VertexShader;
	//Buffer that holds the geometry shader
	GLuint m_GeometryShader;
	//Buffer that holds the fragment shader
	GLuint m_FragmentShader;
	//Buffer that holds the compute shader
	GLuint m_ComputeShader;

	//Buffer that contains the program object
	GLuint m_Program;
};
#endif