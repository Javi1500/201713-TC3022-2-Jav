#include "InputFile.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

bool InputFile::Read(std::string fileName) {
	std::ifstream abrir(fileName);
	std::string _contenst1((
		std::istreambuf_iterator<char>(abrir)), 
			std::istreambuf_iterator<char>());
	_contenst = _contenst1;

	std::ifstream myFile;
	myFile.open(fileName);


	if (myFile.is_open()) {
		while (!myFile.eof()) {
			return true;
		}
	}
	else {
		return false;
	}
	myFile.close();
}

std::string InputFile::GetContents() {
	return std::string(_contenst);
}

