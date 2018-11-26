#include <iostream>
using namespace std;
#include "CList.h"


int main()
{
 	C2List L1;
	int isExit = 0;
	int user_Action = 0;
	int newData = 0;
	unsigned int side = 0;

	while ( isExit != 1){
		cout << "Choose action.." << '\n'
		<< "1 - add Element" << '\n'
		<< "2 - delete Element" << '\n'
		<< "3 - clear List" << '\n'
		<< "4 - print List" << '\n'
		<< "5 - to exitt" << '\n';
		cin >> user_Action;
		
	switch (user_Action)
	{
		case 1:{
			cout << "Enter new Data..";
			cin >> newData;
			cout << "Enter side (0 - left, 1 - right)..";
			cin >> side;
			L1.addElem( side, newData);
		}break;

		case 2:{
			cout << "Enter side (0 - left, 1 - right)..";
			cin >> side;
			L1.deleteElem( side );
		}break;

		case 3:{
			L1.clearList();
		}break;

		case 4:{
			cout << "Enter side (0 - left, 1 - right)..";
			cin >> side;
			L1.printList( side );
		}break;

		case 5:{
			isExit = 1;
		}break;

		default:{
			cout << "Wrong entering" << '\n';
		}
	}
		cout << '\n';
	}
	

	return 0;
}

