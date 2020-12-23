/*******************
 * smartphone.cpp
 *******************/

#include "smartphone.h"

// TODO: Put your SmartPhone methods here

void SmartPhone::prompt()
{
	Phone::promptNumber();
	std::cout << "Email: ";
	std::cin >> email;


}	

void SmartPhone::display()
{
	Phone::display();
	std::cout << email << std::endl;
}