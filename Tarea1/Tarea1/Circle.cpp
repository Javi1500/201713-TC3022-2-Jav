/***************************
Materia:Gráficas Computacionales Gráficas
Fecha: 02/10/2017
Autor: A01374356 Garcia Roque Javier Antonio
*****************************/
#include "Circle.h"
/*Cuando el archivo fuente esta aquí va con comillas*/

Circle::Circle() {
	_radiuos = 1.0;
	_color = "red";

}

Circle::Circle(double r) {
	_radiuos = r;
	_color = "red";
}

Circle::Circle(double r, std::string c){
	_radiuos = r;
	_color = c;
}

double Circle::GetRadius() {
	return _radiuos;
}

double Circle::GetArea() {
	return 3.14159*_radiuos*_radiuos;
}

std::string Circle::GetColor()
{
	return _color;
}

void Circle::SetRadius(double r){
	_radiuos = r;
}

void Circle::SetColor(std::string c){
	_color = c;
}
