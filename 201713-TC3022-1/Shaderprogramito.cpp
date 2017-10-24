#include <iostream>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Shaderprogramito.h"

using namespace std;
GLuint shaderProgram;



//Creando el manager de los shaders. Almacenamos el id en la variable 
//shaderProgram
shaderProgram = glCreateProgram();
//Este manager va a administrar el vertex shader con identificador 
//vertexShaderHandle
glAttachShader(shaderProgram, vertexShaderHandle);
//Este manager va a administrar el fragment shader con el identificador
//fragmentShaderHandle
glAttachShader(shaderProgram, fragmentShaderHandle);
//Asociamos el indice del buffer (VBO) de posiciones con el nombre 
//de la variable correspondiente en el shader
glBindAttribLocation(shaderProgram, 0, "VertexPosition");
//Asociamos el indice del VBO de colores con el nombre de la variable
//correspondiente en el shader
glBindAttribLocation(shaderProgram, 1, "VertexColor");
//Verificamos que las etapas de los shaders pueden trabajar en conjunto
glLinkProgram(shaderProgram);
}