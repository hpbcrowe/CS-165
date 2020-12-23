/*********************
 * phone.cpp
 *********************/
#include "phone.h"

// TODO: Put your phone class methods here...





void Phone::promptNumber()
{

std::cout << "Area Code: ";
std::cin >> areaCode;
std::cout << "Prefix: ";
std::cin >> prefix;
std::cout << "Suffix: ";
std::cin >> suffix;
std::cout << std::endl;
}

void Phone::display()
{
	
	std::cout << "(" << areaCode << ")" << prefix << "-" << suffix << std::endl;
}

