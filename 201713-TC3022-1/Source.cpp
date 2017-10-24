#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

//Identificador del manager de VBOs para 1 conjunto de vertices
GLuint vao;

//Funcion que va a inicializar toda la memoria del programa.
void Initialize()
{
	//Vamos a crear una lista que va a almacenar las posiciones en 2 dimensiones de un 
	//triángulo. Esto es CPU y RAM.
	//vector=lista
	//vec1 sería float no vec1
	//vectores de 2 a 4
	//vec2=(x,y)
	//vec3=(x,y,z)


	std::vector<glm::vec2>positions;
	positions.push_back(glm::vec2(-1.0f, -1.0f));
	positions.push_back(glm::vec2(1.0f, -1.0f));
	positions.push_back(glm::vec2(0.0f, 1.0f));

	std::vector<glm::vec3>colors;




	//Creamos un VAO y almacenamos el id en la variable vao.
	//Este es el manager de VBOs
	
	glGenVertexArrays(1, &vao);

	//Le decimos a OpenGL que queremos utilizar el manager.
	//Todos los VBOs que creemos a partir de este punto y hasta que desactivemos este VAO, se van a asociar
	//a este manager
	glBindVertexArray(vao);

	//Identificador del VBO de posiciones. Aqui lo vamos a almacenar.
	GLuint positionsVBO;

	//Creamos un VBO y almacenamos el id en la variable positionsVBO.
	glGenBuffers(1, &positionsVBO);

	//Le decimos a OpenGL que lo que queremos utilizar como atributo.
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*positions.size(), positions.data(), GL_STATIC_DRAW);

	//Quiero activar el atributo con indice 0 en la tarjeta de video
	glDisableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	//Desacivamos el uso del VBO de posiciones.
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	GLuint colorsVBO;
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*colors.size(), colors.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);



	//Ya no quiero utilizar el VAO. Ya no se asociaran más VBOs a este VAO
	glBindVertexArray(0);

}

void MainLoop()
{
	//Borramos el buffer de color y profundidad siempre al inicio de un nuevo frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//TODO: hacer el render

	//Paso 1: No lo podemos hacer aun
	//Paso2: Activar un VAO
	glBindVertexArray(vao);
	//Paso3: Dibujamos
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//Paso4:Desactivamos el VAO
	glBindVertexArray(0);
	//Paso5: Aún no lo podemos hacer

	//Intercambiar los buffers(el que se estaba rendereando cxon el que se estaba 
	//mostrando
	glutSwapBuffers();

	//WARNING!!! esto es OpenGL clásico y no lo vamos a volver a usar en todo el semestre.
	glBegin(GL_TRIANGLES);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f, -1.0f);


	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, -1.0f);


	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);



	glEnd();
	//FIN DE WARNING


	//Intercambiar los buffers( el que se estaba rendereando con el que se estaba mostrando).
	glutSwapBuffers();
}


int main(int argc, char*argv[])
{


	//Inicializamos freeglut.
	//Freelgut se encarga de generar y manejar ventanas.
	//utilizamos freeglut para crear una ventana donde vamos a dibujar.
	glutInit(&argc, argv);

	//Tenemos que informar que queremos trabajar con el pipeline programable (OpenGL moderno).
	glutInitContextProfile(GLUT_CORE_PROFILE);

	//Freeglut nos permite configurar eventos que ocurren en la ventana.
	//Un evento que nos interesa es cuando alguien cierra la ventana.
	//En este caso, simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//Configuramos el framebuffer. En este caso estamos solicitando un buffer de color
	//true color RGBA, un buffer de profundidad y un segundo buffer para renderear
	//(evitamos parpadeos al renderear).
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	//Solicitamos una ventana de 400x400 pixeles.
	glutInitWindowSize(400,400);

	//Creamos y abrimos la ventana con un título personalizado.
	glutCreateWindow("Hello World OpenGL");

	//Asociar una función de render. Esta función se mandará a llamar para dibujar 
	//un frame.
	glutDisplayFunc(MainLoop);

	//Inicializamos GLEW. Esta librería se encarga de obtener el API de OpenGL de nuestra
	//tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	
	//Configurar OpenGL. Este es el color por default del buffer de color en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	//Configurar la memoria que la aplicacion va a necesitar.
	Initialize();

	//Iniciamos la aplicación gráfica. El main se pausará en esta línea hasta qye
	//se cierre la ventana de OpenGL.
	glutMainLoop();

	return 0;

}