/***************************
Materia:Gráficas Computacionales Gráficas
Fecha: 02/10/2017
Autor: A01374356 Garcia Roque Javier Antonio
*****************************/
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "Transform.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Camera.h"
#include <iostream>
#include <vector>

Mesh _mesh;
ShaderProgram _shaderProgram;
Transform _transform; 
Camera _camera;
float t;
//ui

void Initialize()
{
	
	std::vector<glm::vec3> positions;
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));//3

	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));//4
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));

	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));//8
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));

	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));//12
	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));

	positions.push_back(glm::vec3(-3.0f, 3.0f, 3.0f));//16
	positions.push_back(glm::vec3(-3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(-3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(-3.0f, -3.0f, -3.0f));

	positions.push_back(glm::vec3(3.0f, -3.0f, -3.0f));//20
	positions.push_back(glm::vec3(3.0f, -3.0f, 3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, -3.0f));
	positions.push_back(glm::vec3(3.0f, 3.0f, 3.0f));

	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.5f));

	//Para afuera 
	std::vector<unsigned int> indices = { 0,2,3,3,1,0, 5,4,6,6,7,5, 8,10,11,11,9,8, 15,13,12,12,14,15, 18,19,17,17,16,18, 23,21,20,20, 22, 23 };
	//Crea el mesh
	_mesh.CreateMesh(24);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);

	_shaderProgram.CreateProgram();
	_shaderProgram.Activate();
	_shaderProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	//lamamos el indice
	_mesh.SetIndices(indices, GL_STATIC_DRAW);

	_shaderProgram.LinkProgram();
	_shaderProgram.Deactivate();

	_shaderProgram.Activate();
	//
	_shaderProgram.SetUniformf("iResolution", 400.0f, 400.0f);
	_shaderProgram.Deactivate();

	t=0.0f;
	//_camera.SetOrthographic(15.0f, 1.0f);
	_camera.MoveForward(15.0f, true);
}

void Idle(){
	glutPostRedisplay();
}

void GameLoop()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_shaderProgram.Activate();

	t+= 0.01f;
	_shaderProgram.SetUniformf("iGlobalTime", t);
	//Gira en 3D
	_transform.SetRotation(t*2, t*8, t*4);
	//Matrix modelo
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());
	//pon el tipo de triangulo
	_mesh.Draw(GL_TRIANGLES);
	_shaderProgram.Deactivate();

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	//version
	glutInitContextVersion(4, 0);
	
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);

	glutCreateWindow("Hello World GL");

	glutDisplayFunc(GameLoop);
	glutIdleFunc(Idle);

	glewInit();
	//Color de la pantalla
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	Initialize();

	glutMainLoop();

	return 0;
}