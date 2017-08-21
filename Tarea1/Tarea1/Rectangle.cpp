#include "Rectangle.h"

Rectangle::Rectangle(){
	_width = 1.0;
	_height = 1.0;
}

Rectangle::Rectangle(float w, float h){
	_width = w;
	_height = h;
}

void Rectangle::SetWidth(float w){
	_width = w;
}

void Rectangle::SetHeight(float h){
	_height = h;
}

float Rectangle::GetWidth(){
	return _width;
}

float Rectangle::GetHeight(){
	return _height;
}

float Rectangle::GetArea()
{
	return _width*_height;
}

float Rectangle::GetPerimeter(){
	return (_width * 2) + (_height * 2);
}
