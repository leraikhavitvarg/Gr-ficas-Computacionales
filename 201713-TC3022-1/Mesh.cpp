#include "Mesh.h"
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>






Mesh::Mesh()
{
	_colorsVertexBufferObject = 0;
	_vertexArrayObject = 0;
	_positionsVertexBufferObject = 0;
	_vertexCount = 0;
}

Mesh::~Mesh()
{
	//manager
	//& = identificador para hacer referencia a la memoria
	glDeleteVertexArrays (1, &_vertexArrayObject);
	//atributo
	glDeleteBuffers(1, &_positionsVertexBufferObject);
	glDeleteBuffers(1, &_colorsVertexBufferObject);
	_vertexCount = 0;
}

void Mesh::SetPositionAttribute(vector<glm::vec2> positions, GLenum usage, GLuint locationIndex)
{

	if ((positions.size() > 0) && (_vertexCount == positions.size()))
		SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec2) * positions.size(), positions.data(), usage, locationIndex, 2);

}

void Mesh::Draw(GLenum primitive)
{
	glBindVertexArray(_vertexArrayObject);
	glDrawArrays(primitive,0,_vertexCount);
	glBindVertexArray(0);
}

void Mesh::CreateMesh(GLint vertexCount)
{
	
	_vertexCount = vertexCount;
	glGenVertexArrays(1, &_vertexArrayObject);
	
}

void Mesh::SetColorAttribute(vector<glm::vec3> colors, GLenum usage, GLuint locationIndex)
{
	if ((colors.size() < 0) && (_vertexCount != colors.size()));
	SetAttributeData(_colorsVertexBufferObject, sizeof(glm::vec3) * colors.size(), colors.data(), usage, locationIndex,3);
}

void Mesh::SetAttributeData(GLuint & buffer, GLsizeiptr, const void * data, GLenum usage, GLuint locationIndex, const GLint components)
{
	//Si el buffer ya existía, lo borro
	if (buffer != 0)
		glDeleteBuffers(1, &buffer);

	// Este es el manager de VBOs
	glBindVertexArray(_vertexArrayObject);

	glGenBuffers(1, &buffer);


	// Le decimos a OpenGL que lo queremos utilizar como un atributo.
	glBindBuffer(GL_ARRAY_BUFFER,buffer);

	// Asignamos los datos al buffer y los mandamos a la tarjeta de video.
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	// Quiero activar el atributo con indice 0 en la tarjeta de video
	glEnableVertexAttribArray(locationIndex);
	// Configuramos el atributo con indice 0 en la tarjeta de video.
	glVertexAttribPointer(locationIndex, components, GL_FLOAT, GL_FALSE, 0, nullptr);
	// Desactivamos el uso del VBO de posiciones
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	

	
}



