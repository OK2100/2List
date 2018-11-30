#include <iostream>
#include "CList.h"
using namespace std;

void work_with_User (C2List* const L)
{
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
				L->addElem( side, newData);
			}break;

			case 2:{
				cout << "Enter side (0 - left, 1 - right)..";
				cin >> side;
				L->deleteElem( side );
			}break;

			case 3:{
				L->clearList();
			}break;

			case 4:{
				side = 0;
//				cout << "Enter side (0 - left, 1 - right)..";
//				cin >> side;
				L->printList( side );
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

}


void swop(SListElem* b1, SListElem* e1, SListElem* b2, SListElem* e2)
{
	SListElem* tempptr1;
	SListElem* tempptr2;

	tempptr1 = b1->pPrev;	
	
	b1->pPrev = b2->pPrev;
	(b2->pPrev)->pNext = b1;

	b2->pPrev = tempptr1;
	tempptr1->pNext = b2;

	tempptr2 = e1->pNext;
	
	e1->pNext = e2->pNext;
	(e2->pNext)->pPrev = e1;

	e2->pNext = tempptr2;
	tempptr2->pPrev = e2;

}



int main()
{
 	C2List L1;

	L1.createList(10);
	
	L1.printList(0);

//	work_with_User (&L1);

	SListElem* b1;
	SListElem* e1;
	SListElem* b2;
	SListElem* e2;

	b1 = L1.search(2,1,0);
	e1 = L1.search(4,1,0);
	b2 = L1.search(7,1,0);
	e2 = L1.search(9,1,0);
	
	swop(b1, e1, b2, e2);
	L1.printList(0);	
	
	return 0;
}

