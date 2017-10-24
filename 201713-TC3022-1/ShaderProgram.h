#pragma once
#include <string>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>
#include "Shader.h"


class ShaderProgram
{
private:
	GLuint _programHandle;
	std::vector<std::unique_ptr<Shader>> _attachedShaders;
	void DeleteAndDetachShaders();
	void DeleteProgram();

	
	
public:
	ShaderProgram();
	~ShaderProgram();
	void CreateProgram();
	void AttachShader(std::string path, GLenum type);
	void LinkProgram();
	void Activate();
	void Deactivate();
	void SetAttribute(GLuint locationIndex, std::string name);
	void SetUniform1f(std::string name, float value);
	void SetUniform2f(std::string name, float x, float y);
	void SetUniform3f(std::string name, float x, float y, float z);
	void SetUniform4f(std::string name, float x, float y, float z, float w);


};
