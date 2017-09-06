#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>

GLuint vao;


void Initialize()
{

	std::vector<glm::vec2>positions;
	positions.push_back(glm::vec2(-0.4f, -0.3f));
	positions.push_back(glm::vec2(1.0f, -1.0f));
	positions.push_back(glm::vec2(0.0f, 1.0f));

	std::vector<glm::vec3>colors; 

	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);

	GLuint positionsVBO;

	glGenBuffers(1, &positionsVBO);
	
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*positions.size(), positions.data(), GL_STATIC_DRAW);

	glDisableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	GLuint colorsVBO;
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*colors.size(), colors.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0);

}

void MainLoop()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBindVertexArray(vao);
	
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 9);

	glBindVertexArray(0);

	glutSwapBuffers();

	
	glBegin(GL_TRIANGLE_STRIP);


	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.4f, -0.3f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.4f, 0.3f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.5f, 0.1f);



	glColor3f(0.0f, 0.0f,1.0f);
	glVertex2f(-0.4f,0.3f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.5f, 0.1f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.6f);



	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.4f, 0.3f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.5f, 0.1f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.6f);



	glEnd();
	
	glutSwapBuffers();
}


void MainLoop2()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 9);

	glBindVertexArray(0);

	glutSwapBuffers();
	glBegin(GL_TRIANGLE_STRIP);

	//1st line
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.5f, -0.8f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.5f, 0.1f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.4f, 0.3f);



	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.5f, -0.8f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.5f, 0.1f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.9f, 0.3f);



	//2nd line
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.5f, 0.1f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 1.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.6f);



	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.5f, 0.1f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 1.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.9f, 0.3f);



	//3rd line
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.5f, 0.1f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 1.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.9f, 0.3f);



	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.5f, 0.1f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 1.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.6f);



	//4th line
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.7f, -0.8f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.5f, 0.1f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.9f, 0.3f);



	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.7f, -0.8f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.5f, 0.1f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.3f, -0.4f);



	//5th line
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.7f, -0.8f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.5f, -0.8f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.3f, 0.4f);



	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.5f, -0.8f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.3f, -0.4f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.4f, 0.3f);



	glEnd();
	
	glutSwapBuffers();
}


int main(int argc, char*argv[])
{


	
	glutInit(&argc, argv);

	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(400, 400);

	glutCreateWindow("Voy a morir");

	glutDisplayFunc(MainLoop);


	glewInit();


	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	Initialize();

	glutMainLoop();

	return 0;

}