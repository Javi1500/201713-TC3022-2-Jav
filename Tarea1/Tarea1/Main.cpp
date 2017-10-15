/***************************
Materia:Gr�ficas Computacionales Gr�ficas
Fecha: 02/10/2017
Autor: A01374356 Garcia Roque Javier Antonio
*****************************/
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "Camera.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Transform.h"

Mesh _mesh;
ShaderProgram _shaderProgram;
Transform _transform; //Cada objeto tendra su propio transform por eso debemos crear mas de uno. ahorita solo uno pues solo hau un mesh que es pentagono
Camera _camera;
//ui
void Initialize()
{
	
	std::vector<glm::vec2> positions;
	positions.push_back(glm::vec2(glm::cos(glm::radians(90.0f)), glm::sin(glm::radians(90.0f))));
	positions.push_back(glm::vec2(0.5f * glm::cos(glm::radians(18.0f)), 0.5f * glm::sin(glm::radians(18.0f))));
	positions.push_back(glm::vec2(glm::cos(glm::radians(18.0f)), glm::sin(glm::radians(18.0f))));
	positions.push_back(glm::vec2(0.5f * glm::cos(glm::radians(306.0f)), 0.5f * glm::sin(glm::radians(306.0f))));
	positions.push_back(glm::vec2(glm::cos(glm::radians(306.0f)), glm::sin(glm::radians(306.0f))));
	positions.push_back(glm::vec2(0.5f * glm::cos(glm::radians(234.0f)), 0.5f * glm::sin(glm::radians(234.0f))));
	positions.push_back(glm::vec2(glm::cos(glm::radians(234.0f)), glm::sin(glm::radians(234.0f))));
	positions.push_back(glm::vec2(0.5f * glm::cos(glm::radians(162.0f)), 0.5f * glm::sin(glm::radians(162.0f))));
	positions.push_back(glm::vec2(glm::cos(glm::radians(162.0f)), glm::sin(glm::radians(162.0f))));
	positions.push_back(glm::vec2(0.5f * glm::cos(glm::radians(90.0f)), 0.5f * glm::sin(glm::radians(90.0f))));
	positions.push_back(glm::vec2(glm::cos(glm::radians(90.0f)), glm::sin(glm::radians(90.0f))));
	positions.push_back(glm::vec2(0.5f * glm::cos(glm::radians(18.0f)), 0.5f * glm::sin(glm::radians(18.0f))));

	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));

	_mesh.CreateMesh(12);
	_mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
	_mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);

	_shaderProgram.CreateProgram();
	_shaderProgram.AttachShader("Default.vert", GL_VERTEX_SHADER);
	_shaderProgram.AttachShader("Default.frag", GL_FRAGMENT_SHADER);
	_shaderProgram.SetAttribute(0, "VertexPosition");
	_shaderProgram.SetAttribute(1, "VertexColor");
	_shaderProgram.LinkProgram();
	//Aqui cambiamos en z 90 grafos para que su arriba se mueva 90 grados, esto proboca que en las rotaciones globales gira sobre arriba predeterminado
	//mientras que localguira sobre el arriba del mesh.
	
	//_transform.SetRotation(0.0f, 0.0f, 90.0f);
	_camera.SetOrthographic(2.0f, 1.0f);
}

void GameLoop()
{
	// Limpiamos el buffer de color y el buffer de profunidad.
	// Siempre hacerlo al inicio del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	_transform.Rotate(0.0f, 0.01f, 0.0f, false); //lo vamos a mover lo que diga aqui

	_shaderProgram.Activate();
	_shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());//le enviamos la posicion con un get para que lo ocupe como quiera
	_mesh.Draw(GL_TRIANGLE_STRIP);
	_shaderProgram.Deactivate();

	// Cuando terminamos de renderear, cambiamos los buffers.
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
}

int main(int argc, char* argv[])
{
	// Inicializar freeglut
	// Freeglut se encarga de crear una ventana
	// en donde podemos dibujar
	glutInit(&argc, argv);
	// Solicitando una versi�n espec�fica de OpenGL.
	glutInitContextVersion(4, 0);
	// Iniciar el contexto de OpenGL. El contexto se refiere
	// a las capacidades que va a tener nuestra aplicaci�n
	// gr�fica.
	// En este caso estamos trabajando con el pipeline programable.
	glutInitContextProfile(GLUT_CORE_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear la esscena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// true color RGBA, un buffer de profundidad y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Iniciar las dimensiones de la ventana (en pixeles)
	glutInitWindowSize(400, 400);
	// Creamos la ventana y le damos un t�tulo.
	glutCreateWindow("Hello World GL");
	// Asociamos una funci�n de render.
	//Esta funci�n se mandar� a llamar para dibujar un frame.
	glutDisplayFunc(GameLoop);
	// Asociamos una funci�n para el cambio de resoluci�n
	// de la ventana. Freeglut la va a mandar a llamar
	// cuando alguien cambie el tama�o de la venta.
	glutReshapeFunc(ReshapeWindow);
	// Asociamos la funci�n que se mandar� a llamar
	// cuando OpenGL entre en modo de reposo.
	glutIdleFunc(Idle);

	// Inicializar GLEW. Esta librer�a se encarga de obtener el API de OpenGL de
	// nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// Configurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	// Ademas de solicitar el buffer de profundidad, tenemos
	// que decirle a OpenGL que lo queremos activo
	glEnable(GL_DEPTH_TEST);
	// Activamos el borrado de caras traseras.
	// Ahora todos los triangulos que dibujemos deben estar en CCW
	glEnable(GL_CULL_FACE);
	// No dibujar las caras traseras de las geometr�as.
	glCullFace(GL_BACK);

	std::cout << glGetString(GL_VERSION) << std::endl;

	// Configuraci�n inicial de nuestro programa.
	Initialize();

	// Iniciar la aplicaci�n. El main se pausar� en esta l�nea hasta que se cierre
	// la venta de OpenGL.
	glutMainLoop();

	return 0;
}