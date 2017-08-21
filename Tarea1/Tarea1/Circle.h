#pragma once

#include<string>

class Circle {
public:
	Circle();
	Circle(double r); /*Los constructores no tienen tipo de regreso los demás si*/
	Circle(double r, std::string c);

	double GetRadius();
	double GetArea();
	std::string GetColor();

	void SetRadius(double r);
	void SetColor(std::string c);

private:
	double _radiuos;
	std::string _color;
};