#pragma once
#include <string>
#include <iostream>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>


using namespace std;

class Mesh
{


	public:
		Mesh();
		~Mesh();
		void SetPositionAttribute(vector<glm::vec2> positions ,GLenum usage, GLuint locationIndex);
		void SetPositionAttribute(vector<glm::vec3> positions, GLenum usage, GLuint locationsIndex);
		void Draw(GLenum primitive);
		void CreateMesh(GLint vertexCount);
		void SetColorAttribute(vector<glm::vec3> colors, GLenum usage, GLuint locationIndex);
		void SetColorAttribute(vector<glm::vec4> colors, GLenum usage, GLuint locationIndex);
	


	private:
		void SetAttributeData(GLuint& buffer, GLsizeiptr, const void* data, GLenum usage, GLuint locationIndex, const GLint components);
		GLuint _colorsVertexBufferObject;
		GLuint _vertexArrayObject;
		GLuint _positionsVertexBufferObject;
		GLint _vertexCount;
		GLsizeiptr size;

	





};