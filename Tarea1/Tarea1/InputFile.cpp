#include "InputFile.h"
#include <fstream>

bool InputFile::Read(std::string fileName){
	std::ifstream myFile;
	myFile.open(fileName);

	if (myFile.is_open()) {
		//while (!myFile.eof()) {
			//myFile >> _contenst;
			//return true;
		//}
	}
	else {
		return false;
	}
	myFile.close();
}

std::string InputFile::GetContents(){
	return std::string(_contenst);
}


