#include "Shader.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>


Shader::Shader()
{
	//El constructor nicializa los valores por default de las variables
	GLuint _shaderHandle = 0;
}

Shader::~Shader()
{
	//El destructor borra el shader por la variable _shaderHandle
	void glDeleteShader(GLuint _shaderHandle);
	
}

void Shader::CreateShader(std::string path, GLenum type)
{
	//Carga el código, crea y compila un archivo shader 
	//path :codigo fuente del shader
	void glCompileShader(GLuint path); 

	//Nuevo shader tipo type y guarda su identificador en la variable _shaderHandle
	_shaderHandle = type;
	
	void glDeleteShader(GLuint &_shaderHandle);
	GLuint glCreateShader(GLenum type);
	void glShaderSource(GLuint &_shaderHandle, GLsizei count, const GLchar** string, const GLint*length);
	void glCompileShader(GLuint &_shaderHandle);



}

GLuint Shader::GetHandle()
{

	return _shaderHandle;
}
