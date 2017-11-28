#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Camera.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"
#include <IL/il.h>
#include "Texture2D.h"
Camera _camera;
Mesh _mesh;
//base
Transform _transform;
//piso
Transform _transform2;
Transform _derecha;
Transform _izquierda;
Transform _trasera;
Transform _frontal;
Transform _superior;
Transform _inferior;
Transform _pivote1;
Transform _pivote2;
Transform _pivote3;
Transform _pivote4;
Transform _pivote5;
ShaderProgram _shaderProgram;
Texture2D myTexture;
Texture2D myTexture2;

float _rotarZ = 0.0f;
float _delta = 0.0375f;

glm::vec3 _LightPosition;
glm::vec3 _LightColor;
glm::vec3 _AmbientLight;
glm::mat3 _NormalMatrix;
glm::mat3 _NormalMatrix2;
glm::vec3 _CameraPosition = _camera.GetPosition();
// Función que va a inicializar toda la memoria del programa.
void Initialize()
{
	// Vamos a crear una lista que va a almacenar las posiciones
	// en 2 dimensiones de un triángulo.
	// Esto es en CPU y RAM.
	std::vector<glm::vec3> positions;
	// Cara frontal
	positions.push_back(glm::vec3(-3.0f, -0.25f, 3.0f)); //C		0
	positions.push_back(glm::vec3(3.0f, -0.25f, 3.0f)); //D		1
	positions.push_back(glm::vec3(3.0f, 0.25f, 3.0f)); //B		2
	positions.push_back(glm::vec3(-3.0f, 0.25f, 3.0f)); //A		3
														// Cara lateral derecha
	positions.push_back(glm::vec3(3.0f, -0.25f, 3.0f)); //D		4
	positions.push_back(glm::vec3(3.0f, -0.25f, -3.0f)); //H		5
	positions.push_back(glm::vec3(3.0f, 0.25f, -3.0f)); //F		6
	positions.push_back(glm::vec3(3.0f, 0.25f, 3.0f)); //B		7
													   // Cara trasera 
	positions.push_back(glm::vec3(-3.0f, -0.25f, -3.0f)); //G	8
	positions.push_back(glm::vec3(-3.0f, 0.25f, -3.0f)); //E		9
	positions.push_back(glm::vec3(3.0f, 0.25f, -3.0f)); //F		10
	positions.push_back(glm::vec3(3.0f, -0.25f, -3.0f)); //H		11
														 //Cara Lateral izquierda 
	positions.push_back(glm::vec3(-3.0f, 0.25f, 3.0f)); //A		12	
	positions.push_back(glm::vec3(-3.0f, 0.25, -3.0f)); //E		13
	positions.push_back(glm::vec3(-3.0f, -0.25f, 3.0f)); //C		14	
	positions.push_back(glm::vec3(-3.0f, -0.25f, -3.0f)); //G	15
														  // Tapa inferior 
	positions.push_back(glm::vec3(-3.0f, -0.25f, 3.0f)); //C		16
	positions.push_back(glm::vec3(-3.0f, -0.25f, -3.0f)); //G	17
	positions.push_back(glm::vec3(3.0f, -0.25f, -3.0f)); //H		18
	positions.push_back(glm::vec3(3.0f, -0.25f, 3.0f)); //D		19
														// Tapa superior 
	positions.push_back(glm::vec3(-3.0f, 0.25f, 3.0f)); //A		20
	positions.push_back(glm::vec3(3.0f, 0.25f, 3.0f)); //B		21
	positions.push_back(glm::vec3(-3.0f, 0.25f, -3.0f)); //E		22
	positions.push_back(glm::vec3(3.0f, 0.25f, -3.0f)); //F		23

														// Vamos a crear una lista para almacenar colores RGB
														// Esta lista está en CPU y RAM
	std::vector<glm::vec3> colors;
	// Cara frontal
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	// Cara lateral derecha
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	// Cara trasera 
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	//Cara lateral izquierda 
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
	//Tapa inferior 
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
	// Tapa superior 
	colors.push_back(glm::vec3(0.50f, 0.1f, 0.3f));
	colors.push_back(glm::vec3(0.50f, 0.1f, 0.3f));
	colors.push_back(glm::vec3(0.50f, 0.1f, 0.3f));
	colors.push_back(glm::vec3(0.50f, 0.1f, 0.3f));

	std::vector<glm::vec3> normals;

	//frontal 
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	//derecha 
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

	//trasera 
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
	normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));

	//izquierda 
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
	normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));

	//inferior 
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));

	//superior 
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

	//COORDENADAS TEXTURAS 

	std::vector<glm::vec2> textures;
	//Frontal
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	//Derecha
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	//trasera 
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	//Izquierda 
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	//Inferior 
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));
	//Superior 
	textures.push_back(glm::vec2(0.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 0.0f));
	textures.push_back(glm::vec2(1.0f, 1.0f));
	textures.push_back(glm::vec2(0.0f, 1.0f));

	myTexture.LoadTexture("textura_rosita.png"); //ruta 
	myTexture2.LoadTexture("textura_pizarron.png");







	std::vector<unsigned int> indices = { 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 11, 8, 10, 12, 13, 15, 12, 15, 14, 16, 17, 18, 16, 18, 19, 22, 20, 23, 20, 21, 23 };

	_mesh.CreateMesh(24);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
	_mesh.SetNormalAttribute(normals, GL_STATIC_DRAW, 2);
	_mesh.SetTexCoordAttribute(textures, GL_STATIC_DRAW, 3);

	_mesh.SetIndices(indices, GL_STATIC_DRAW);

	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("PhongShader.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("PhongShader.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.SetAttribute(2, "VertexNormals");
	_shaderProgram.SetAttribute(3, "VertexTextures");


	//Declaramos la luz 
	_LightPosition.x = -5.0f;
	_LightPosition.y = 5.0f;
	_LightPosition.z = 5.0f;


	//Definimos color
	_LightColor.x = 1.0f;
	_LightColor.y = 1.0f;
	_LightColor.z = 1.0f;

	_shaderProgram.LinkProgram();
	_shaderProgram.Activate();
	_shaderProgram.SetUniformf("_LightColor", _LightColor);
	_shaderProgram.SetUniformf("_LightPosition", _LightPosition);
	_shaderProgram.SetUniformf("_CameraPosition", _CameraPosition);

	_shaderProgram.Deactivate();

	_transform.SetPosition(0.0f, 0.0f, -20.0f);
	_transform2.SetPosition(0.0f, -7.0f, -20.0f);
	_transform2.SetScale(8.0f, 0.05f, 10.0f);
	_derecha.SetPosition(0.0f, 3.0f, 0.0f);
	_derecha.SetRotation(0.0f, 0.0f, 90.0f);
	_pivote1.SetPosition(3.0f, 0.0f, 0.0f);
	_izquierda.SetPosition(0.0f, 3.0f, 0.0f);
	_izquierda.SetRotation(0.0f, 0.0f, -90.0f);
	_pivote2.SetPosition(-3.0f, 0.0f, 0.0f);
	_trasera.SetPosition(0.0f, 3.0f, 0.0f);
	_trasera.SetRotation(90.0f, 0.0f, 0.0f);
	_pivote3.SetPosition(0.0f, 0.0f, -3.0f);
	_frontal.SetPosition(0.0f, 3.0f, 0.0f);
	_frontal.SetRotation(-90.0f, 0.0f, 0.0f);
	_pivote4.SetPosition(0.0f, 0.0f, 3.0f);
	_superior.SetPosition(0.0f, 3.0f, 0.0f);
	_superior.SetRotation(0.0f, 0.0f, -90.0f);
	_pivote5.SetPosition(3.0f, 0.0f, 0.0f);
	//_superior.SetPosition()





}
void MainLoop()
{
	// Borramos el buffer de color y profundidad siempre al inicio de un nuevo frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_transform.Rotate(0.0f, 0.01f, 0.0f, true);

	_pivote2.SetRotation(0.0f, 0.0f, _rotarZ);
	_pivote1.SetRotation(0.0f, 0.0f, -_rotarZ);
	_pivote5.SetRotation(0.0f, 0.0f, -_rotarZ);
	_pivote3.SetRotation(-_rotarZ, 0.0f, 0.f);
	_pivote4.SetRotation(_rotarZ, 0.0f, 0.f);

	_rotarZ += _delta;
	if (_rotarZ > 90.0f) {
		_delta *= -1.0f;
		_rotarZ = 90.0f;
	}

	else if (_rotarZ < 0.0f) {
		_delta *= -1.0f;
		_rotarZ = 0.0f;
	}


	//_pivote1.SetRotation(0.0f, 0.0f, 90.0f);
	_shaderProgram.Activate();
	//Cubo1 chingón



	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());
	_NormalMatrix = glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix())));
	_shaderProgram.SetUniformMatrix("_transform", _transform.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("_NormalMatrix", _NormalMatrix);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture2", 1);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();



	//Hijito 1 Derecho

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix()* _pivote1.GetModelMatrix()* _derecha.GetModelMatrix());
	_NormalMatrix = glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix()* _pivote1.GetModelMatrix()* _derecha.GetModelMatrix())));
	_shaderProgram.SetUniformMatrix("_transform", _transform.GetModelMatrix()* _pivote1.GetModelMatrix()* _derecha.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("_NormalMatrix", _NormalMatrix);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture2", 1);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	//Hijito 2 Izquierdo

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix()* _pivote2.GetModelMatrix()* _izquierda.GetModelMatrix());
	_NormalMatrix = glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix()* _pivote2.GetModelMatrix()* _izquierda.GetModelMatrix())));
	_shaderProgram.SetUniformMatrix("_transform", _transform.GetModelMatrix()* _pivote2.GetModelMatrix()* _izquierda.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("_NormalMatrix", _NormalMatrix);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture2", 1);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();

	//Hijito 3 Trasera

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix()* _pivote3.GetModelMatrix()* _trasera.GetModelMatrix());
	_NormalMatrix = glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix()* _pivote3.GetModelMatrix()* _trasera.GetModelMatrix())));
	_shaderProgram.SetUniformMatrix("_transform", _transform.GetModelMatrix()* _pivote3.GetModelMatrix()* _trasera.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("_NormalMatrix", _NormalMatrix);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture2", 1);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();

	//Hijito 4 Frontal

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix()* _pivote4.GetModelMatrix()* _frontal.GetModelMatrix());
	_NormalMatrix = glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix()* _pivote4.GetModelMatrix()* _frontal.GetModelMatrix())));
	_shaderProgram.SetUniformMatrix("_transform", _transform.GetModelMatrix()* _pivote4.GetModelMatrix()* _frontal.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("_NormalMatrix", _NormalMatrix);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture2", 1);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();
	//Nieto 

	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection()* _transform.GetModelMatrix()* _pivote1.GetModelMatrix()* _derecha.GetModelMatrix()*_pivote5.GetModelMatrix()*_superior.GetModelMatrix());
	_NormalMatrix = glm::transpose(glm::inverse(glm::mat3(_transform.GetModelMatrix()* _pivote1.GetModelMatrix()* _derecha.GetModelMatrix()*_pivote5.GetModelMatrix()*_superior.GetModelMatrix())));
	_shaderProgram.SetUniformMatrix("_transform", _transform.GetModelMatrix()* _pivote1.GetModelMatrix()* _derecha.GetModelMatrix()*_pivote5.GetModelMatrix()*_superior.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("_NormalMatrix", _NormalMatrix);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture2", 1);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();

	//Piso 
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform2.GetModelMatrix());
	_NormalMatrix2 = glm::transpose(glm::inverse(glm::mat3(_transform2.GetModelMatrix())));
	_shaderProgram.SetUniformMatrix("_transform", _transform2.GetModelMatrix());
	_shaderProgram.SetUniformMatrix("_NormalMatrix", _NormalMatrix);
	_shaderProgram.SetUniformi("DiffuseTexture", 0);
	_shaderProgram.SetUniformi("DiffuseTexture2", 1);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Bind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Bind();
	_mesh.Draw(GL_TRIANGLES);
	glActiveTexture(GL_TEXTURE0);
	myTexture.Unbind();
	glActiveTexture(GL_TEXTURE1);
	myTexture2.Unbind();

	//matriz de normales transformacion 1





	_shaderProgram.Deactivate();



	// Intercambiar los buffers (el que se estaba rendereando con el que se estaba
	// mostrando).
	glutSwapBuffers();


}

void Idle()
{
	// Cuando OpenGL entra en modo de reposo 
	// (para guardar bateria, por ejemplo)
	// le decimos que vuelva a dibujar ->
	// Vuelve a mandar a llamar GameLoop
	glutPostRedisplay();
}

void ReshapeWindow(int width, int height)
{
	glViewport(0, 0, width, height);
	_camera.SetPerspective(1.0f, 1000.0f, 60.0f, (float)width / (float)height); 	//camera.setpersective y mandar llamar el 
}

int main(int argc, char* argv[])
{
	// Inicializamos freeglut. 
	// Freeglut se encarga de generar y manejar ventanas.
	// Utilizamos freeglut para crear una ventana donde vamos a dibujar.
	glutInit(&argc, argv);
	// Tenemos que informar que queremos trabajar con el pipeline
	// programable (OpenGL moderno).
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// de color true color RGBA, un buffer de profundidad y un segundo buffer 
	// para rendererar (evitamos parpadeos al renderear).
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Solicitamos una ventana de 400x400 pixeles.
	glutInitWindowSize(1200, 800);
	// Creamos y abrimos la ventana con un título personalizado.
	glutCreateWindow("Hello World OpenGL");
	// Asociar una función de render. Esta función se mandará a llamar para 
	// dibujar un frame.
	glutDisplayFunc(MainLoop);
	// Asociamos una función para el cambio de resolución
	// de la ventana. Freeglut la va a mandar a llamar
	// cuando alguien cambie el tamaño de la venta.
	glutReshapeFunc(ReshapeWindow);

	// Asociamos la función que se mandará a llamar
	// cuando OpenGL entre en modo de reposo.
	glutIdleFunc(Idle);

	// Inicializamos GLEW. Esta librería se encarga de obtener el API
	// de OpenGL de nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// COnfigurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	// Ademas de solicitar el buffer de profundidad, tenemos
	// que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	// Activamos el borrado de caras traseras.
	// Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	// No dibujar las caras traseras de las geometrías.
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;
	//Inicializando DevIL 
	ilInit();
	ilEnable(IL_ORIGIN_SET);
	ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
	// Configurar la memoria que la aplicación va a necesitar.
	Initialize();

	// Iniciamos la aplicacion gráfica. El main se pausará en estea línea
	// hasta que se cierre la ventana de OpenGL.
	glutMainLoop();

	return 0;
}