/***************************
Materia:Gráficas Computacionales Gráficas
Fecha: 14/08/2017
Autor: A01374356 Garcia Roque Javier Antonio
*****************************/
#include <iostream>
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
		}
	}
	if (aux>2) {
		return false;
	}
	else {
		return true;
	}
}