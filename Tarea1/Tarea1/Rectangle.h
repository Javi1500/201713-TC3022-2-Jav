/***************************
Materia:Gráficas Computacionales Gráficas
Fecha: 02/10/2017
Autor: A01374356 Garcia Roque Javier Antonio
*****************************/
#pragma once
#include<string>

class Rectangle {
public:
	Rectangle();
	Rectangle(float w, float h);

	void SetWidth(float w);
	void SetHeight(float h);
	
	float GetWidth();
	float GetHeight();
	float GetArea();
	float GetPerimeter();

private:
	float _width;
	float _height;
};