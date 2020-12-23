/***********************************************************************
* Program:
*    Checkpoint 08a, Checkpoint 08a   Inheritance
*    Brother Dudley, CS165
* Author:
*    Ben Crowe
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Book
{
protected:
	string title;
	string author;
	int publicationYear;
public:
	void promptBookInfo()
	{
		cout << "Title: ";
		getline(cin, title);
		cout << "Author: ";
		getline(cin, author);
		cout << "Publication Year: ";
		cin.ignore();
		cin >> publicationYear;
		
		
		
	}

	void displayBookInfo()
	{
		cout << endl;
		cout << title << " (" << publicationYear << ") by " << author << endl;
		
	}



};

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
	Book book;
	book.promptBookInfo();
	book.displayBookInfo();
   return 0;
}
