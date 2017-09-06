#include "InputFile.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string InputFile::GetContents()
{

	return std::string();
	std::string _contents = myFile.GetContents();
	std::cout << "Contents:Hello World Text" << _contents << std::endl;
	std::cout << "File, Bye" << _contents << std::endl;
}

bool InputFile::Read(std::string filename)
{
	return false;
}

bool InputFile::Read(std::string filename)
{
	ifstream myFile;
	std::string filename ="Prueba.txt";
	InputFile myFile;
	myFile.open(filename);

	std::string _contents;

	//Error
	if (myFile.fail()) {
		cout << "Error al abrir el archivo" << endl;
		return false;
	}
	else {

		myFile.open(filename);
		myFile.close();

	}

}
