/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Dudley, CS165
* Author:
*    Ben Crowe
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/
#include <vector>
#include <string>
#include <iostream>
using namespace std;



/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
	vector <int> numberList;
	vector <string> stringList;

	int numbers =1;
	string words;


	//Fill in vector of numbers
	
	while (numbers != 0)
	{
		cout << "Enter int: ";
		cin >> numbers;
		
		numberList.push_back(numbers);
	}
	numberList.pop_back();
	cout << "Your list is:";
	for (int i = 0; i < numberList.size(); ++i)
	{
		cout << numberList[i] << endl;
	}
	

	while (words != "quit")
	{
		cout << "Enter string: ";
		cin >> words;

		stringList.push_back(words);
	}
	stringList.pop_back();
	cout << "Your list is:";

	for (int i = 0; i < stringList.size(); ++i)
	{
		cout << stringList[i] << endl;
	}



   return 0;
}


