/***************************
Materia:Gráficas Computacionales Gráficas
Fecha: 14/08/2017
Autor: A01374356 Garcia Roque Javier Antonio
*****************************/
/*#include <iostream>
#include "InputFile.h"
int PerimetroRectangulo(int, int);
float AreaTriangulo(float, float);
int Mayor(int, int, int);
int Menor(int, int, int);
void FilaEstrellas(int);
void MatrizEstrellas(int);
void PiramideEstrellas(int);
void FlechaEstrellas(int);
void Fibonacci(int);
bool EsPrimo(int);

int main() {
	int x = PerimetroRectangulo(5, 3);
	std::cout << x << std::endl;
	float y = AreaTriangulo(5.0f, 3.0f);
	std::cout << y << std::endl;
	int mayor = Mayor(5, 9, 1);
	std::cout << mayor << std::endl;
	int menor = Menor(5, 9, 1);
	std::cout << menor << std::endl;
	FilaEstrellas(5);
	MatrizEstrellas(4);
	PiramideEstrellas(6);
	FlechaEstrellas(3);
	Fibonacci(9);
	bool primo = EsPrimo(52);
	std::cout << primo << std::endl;


	std::string filename = "Prueba.txt";
	InputFile myFile;
	myFile.Read(filename);
	std::string contents = myFile.GetContents();
	std::cout << "Contens: " << contents << std::endl;
	std::cin.get();
	return 0;
}

int PerimetroRectangulo(int base, int altura) {
	return (base * 2) + (altura * 2);
}

float AreaTriangulo(float base, float altura) {
	return (base*altura) / 2;
}

int Mayor(int numero1, int numero2, int numero3) {
	if (numero1 >= numero2 && numero1 >= numero3) {
		return numero1;
	}
	if (numero2 >= numero1 && numero2 >= numero3) {
		return numero2;
	}
	if (numero3 >= numero2 && numero3 >= numero1) {
		return numero3;
	}
}

int Menor(int numero1, int numero2, int numero3) {
	if (numero1 <= numero2 && numero1 <= numero3) {
		return numero1;
	}
	if (numero2 <= numero1 && numero2 <= numero3) {
		return numero2;
	}
	if (numero3 <= numero2 && numero3 <= numero1) {
		return numero3;
	}
}

void FilaEstrellas(int n) {
	for (int i = 0; i<n; i++) {
		std::cout << "*";
	}
	std::cout << "" << std::endl;
}

void MatrizEstrellas(int n) {
	int cont = 0;
	while (cont<n) {
		for (int i = 0; i<n; i++) {
			std::cout << "*";
		}
		std::cout << "" << std::endl;
		cont++;
	}
}

void PiramideEstrellas(int n) {
	int cont = n - 1;
	while (cont >= 0) {
		for (int i = 0; i<n - cont; i++) {
			std::cout << "*";
		}
		std::cout << "" << std::endl;
		cont--;
	}
}

void FlechaEstrellas(int n) {
	int cont = n - 1;
	while (cont >= 0) {
		for (int i = 0; i<n - cont; i++) {
			std::cout << "*";
		}
		std::cout << "" << std::endl;
		cont--;
	}
	cont = n - 1;
	while (cont>0) {
		for (int i = n - 1; i>0; i -= 1) {
			std::cout << "*";
		}
		std::cout << "" << std::endl;
		n--;
		cont--;
	}
}

void Fibonacci(int n) {
	int cont = 1;
	int a = 0;
	int b;
	for (int i = 0; i <= n; i++) {
		std::cout << cont;
		b = cont;
		cont = cont + a;
		a = b;
	}
	std::cout << "" << std::endl;
}

bool EsPrimo(int numero) {
	int aux = 0;
	for (int i = 1; i <= numero; i++) {
		if (numero%i == 0) {
			aux++;
			/*comprobar cuanto da el aux std::cout<<aux;*/
	/*	}
	}
	if (aux>2) {
		return false;
	}
	else {
		return true;
	}
}*/

#include <iostream>
#include <GL/glew.h> /*Obtiene la ultima version de GL, va en <> pues se importa de fuera*/
#include <GL/freeglut.h>
#include <vector>
#include <glm/glm.hpp> //Datos con dos o mas componentes 

//Identificador del manager al que vamos a asociar todos los VBO´s
GLuint vao;

void Initialize() {
	//Creando toda la memoria que el prograba va a utilizar
	
	//Creacion del atributo de posiciones de los vertices
	//Esta es una lista de vec2
	//Esto es en el CPU
	std::vector<glm::vec2> positions;
	positions.push_back(glm::vec2(-1.0f, -1.0f));
	positions.push_back(glm::vec2(1.0f, -1.0f));
	positions.push_back(glm::vec2(0.0f, 1.0f));

	//Queremos geenerar un manager 
	glGenVertexArrays(1, &vao);
	//Utilizar el vao. A parti de este momento, todos los vBO´s creados y configurados
	glBindVertexArray(vao);

	//Identificador del VBO de posiciones 
	GLuint positionsVBO;
	//Creacion del VBO de posiciones
	glGenBuffers(1, &positionsVBO);//Cuantos y donde queremos almacenarlo
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	//Creamos la memoria y la incializamos con los daos del atributo de posiciones
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2)*positions.size(), positions.data(), GL_STATIC_DRAW);
	//Activamos este numero de atributo en la tarjeta de video.
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	//Ya no vamos a utilizar VBO en este momento.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//Desactivamos el manager
	glBindVertexArray(0);
}


void GameLoop() {
	//Limpiamos el buffer de color y el de profundidad. siempre hacerlo al inico del frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Activamos el manager y en este momento se activan todos los VBO´s asociados automaticamente
	glBindVertexArray(vao);
	//Funcion de dibujo sin indices 
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//Terminamos de usar el manager
	glBindVertexArray(0);

	//Warning.!!! Esto es openGL viejo. Solamente se utilizara esta clase.
	//glBegin(GL_TRIANGLES);
	///Rojo verde azul
	/*glColor3f(1.0f, 0.0f, 0.0f);
	//Vertices 2f=X y Y
	glVertex2f(-1.0f, -1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);*/

	//glEnd();

	//cuandot erminamos de renderear, cambiamos los buffers
	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	/*std::cout << "Hello world" << std::endl;
	Circle circulo(2.0, "green");
	std::cout << circulo.GetRadius() << std::endl;
	Rectangle rectangulo(2.0, 2.0);
	std::cout << rectangulo.GetWidth() << std::endl;
	std::cin.get();*/

	//Inicializar freeglut
	//Freeglut se encarga de crear una ventana
	//En donde podemos dibujar
	glutInit(&argc, argv);
	//Iniciar la versión especifica de openGL
	glutInitContextVersion(4,4);
	//Iniciar el contexto de openGL. El contesto se refiere a las capacidades que tendra nuestra aplicacion grafica 
	//En este caso estamos trabajando con el pipeline clasico
	glutInitContextProfile(GLUT_CORE_PROFILE); //Abres la ventana para que sea compatible con el viejito gl
											   //Freeglut nos permite configurar eventos que ocurren en la ventana.
											   //Un evento que nos interesa es cuando alguien cierra la ventana. En este casi dejamos de renderear la escena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//Configuramos el framebuffer. En este caso estamos solicitando un buffer true color RGBA, un buffer de profundidad 
	//Y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	//indicamos la dimension de nuestra pantalla en pixeles 
	glutInitWindowSize(400, 400);
	//Creamos la ventana y le damos un titulo
	glutCreateWindow("Hello World GL");

	//Asociamos una funcion de render, la cual se manadara a llamar para dibujar un frame 
	glutDisplayFunc(GameLoop);

	//Inicializamos GLEW. esta libreria se encarga de obtener el API de openGL de nuestra tarjeta de video. 
	glewInit();

	//Configurar OpenGL.}
	//Este es el color por default en el framebuffer (amarillo).
	glClearColor(.7f, 1.0f, 0.5f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;

	//configuracion incial de nujestro programa.
	Initialize();

	//iniciada la aplicación el main se va a pausar en esta linea hasta que se cierre la ventana OpenGL.
	glutMainLoop();

	return 0;
}
