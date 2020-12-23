/****************
 * smartphone.h
 ****************/

#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include "phone.h" 
#include <string>
#include <iomanip>

// TODO: Put your SmartPhone definition here

class SmartPhone : public Phone
{
public:
	void prompt();
	void display();
private:
	std::string email;

};



#endif
