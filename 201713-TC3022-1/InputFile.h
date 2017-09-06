#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class InputFile

{


private:
	
	string myFile;


public:
	std::string GetContents();
	bool Read(std::string filename);







};