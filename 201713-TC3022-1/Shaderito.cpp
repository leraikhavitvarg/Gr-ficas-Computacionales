#include <iostream>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Shaderito.h"

using namespace std;
GLuint shaderProgram;

//Leemos el código fuente del vertex shader con la clase auxiliar
//InputFile
shaderito.Read("Default.vert");

//Obtenemos los contenidos leídos y los almacenamos en un string
//vertexSource
std::string vertexSource = shaderito.GetContents();
//Hacemos un cast (conversión de tipo dato) porque no le podemos
//mandar strings a OpenGL. Necesitamos mandarle const GLchar*.
const GLchar * vertexSource_c =
(const GLchar*)vertexSource.c_str();
//Creamos un shader de tipo Vertex Shader y guardamos su id en la 
//variable vertexShaderHandle
GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
//Le mandamos el código fuente que leímos previamente a OpenGL
glShaderSource(vertexShaderHandle, 1, &vertexSource_c, nullptr);
//Le pedimos que lo compile
glCompileShader(vertexShaderHandle);

GLint vertexShaderCompileSuccess = 0;
glGetShaderiv(vertexShaderHandle, GL_COMPILE_STATUS, &vertexShaderCompileSuccess);

if (vertexShaderCompileSuccess == GL_FALSE)
{
	GLint logLength = 0;
	glGetShaderiv(vertexShaderHandle, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength > 0)
	{
		std::vector<GLchar>compileLog(logLength);
		glGetShaderInfoLog(vertexShaderHandle, logLength, &logLength, &compileLog[0]);

		for (int i = 0; i < logLength; i++)
		{
			std::cout << compileLog[i];
		}
		std::cout << std::endl;
	}
	std::cout << "Shader Default.vert did not compiled." << std::endl;
}

ifile.Read("Default.frag");
std::string fragmentSource = ifile.GetContents();
const GLchar*fragmentSource_c = (const GLchar*)fragmentSource.c_str();
GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragmentShaderHandle, 1, &fragmentSource_c, nullptr);
glCompileShader(fragmentShaderHandle);