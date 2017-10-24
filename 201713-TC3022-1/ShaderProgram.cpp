#include "ShaderProgram.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Shader.cpp"


ShaderProgram::ShaderProgram()
{
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram()
{
	DeleteProgram();
}

void ShaderProgram::CreateProgram()
{
	_programHandle = glCreateProgram();
}

void ShaderProgram::AttachShader(std::string path, GLenum type)
{
	std::unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(path, type);
	_attachedShaders.push_back(std::move(shader));

}

void ShaderProgram::LinkProgram()
{
	for (int i = 0; i < _attachedShaders.size(); i++)
	{
		glAttachShader(_programHandle, _attachedShaders[i]->GetHandle());
		std::cout << i << std::endl;
	}

	glLinkProgram(_programHandle);
	DeleteAndDetachShaders();
}

void ShaderProgram::Activate()
{
	glUseProgram(_programHandle);
}

void ShaderProgram::Deactivate()
{
	glUseProgram(0);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name)
{

	//1.manager, 2.    ,3. 
	glBindAttribLocation(_programHandle, locationIndex, name.c_str());
}



void ShaderProgram::SetUniform1f(std::string name, float value)
{
	GLuint loc = glGetUniformLocation(_programHandle,name.c_str);
	void glUniform1f(GLint loc, GLfloat value);
}

void ShaderProgram::SetUniform2f(std::string name, float x, float y)
{
	GLuint loc = glGetUniformLocation(_programHandle, name.c_str);
	void glUniform2f(GLint loc, GLfloat x, GLfloat y);
}

void ShaderProgram::SetUniform3f(std::string name, float x, float y, float z)
{
	GLuint loc = glGetUniformLocation(_programHandle, name.c_str); 
	void glUniform3f(GLint loc, GLfloat x, GLfloat y, GLfloat z);
}

void ShaderProgram::SetUniform4f(std::string name, float x, float y, float z, float w)
{
	GLuint loc = glGetUniformLocation(_programHandle, name.c_str);
	void glUniform4f(GLint loc, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
}


void ShaderProgram::DeleteAndDetachShaders()
{
	//cómo hacer que vaya eliminando la lista de _attachedShaders y eliminarlos 1 por 1.
	glDetachShader(_programHandle,_attachedShaders.push_back);
	
	for (int i = 0; i < _attachedShaders.size(); i++)
	{
		glDetachShader(_programHandle, _attachedShaders[i]->GetHandle());
		std::cout << i << std::endl;
	}

	}


void ShaderProgram::DeleteProgram()
{
	GLuint DeleteAndDetachShaders(_programHandle);
}