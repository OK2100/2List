#include <iostream> 
using namespace std;
#include "CList.h"


C2List::C2List()
{
	pFirst = NULL;
	pLast = NULL;
}


C2List::~C2List()
{
	clearList();
}


SListElem* C2List::getFirst()
{
	return pFirst;
}


SListElem* C2List::getLast()
{
	return pLast;
}


void C2List::clearList()
{
	int N = sizeofList();
	
	for (int i = 1; i <= N; i++){
		deleteElem(0);
	}	
}


void C2List::printList( unsigned int side)
{
	SListElem *pointer = NULL;
	int N = sizeofList();
	
	cout << '\n';

	if (N > 0){

		if (side == 0){
			pointer = pFirst;
			for (int i = 1; i <= N; i++){
				cout << pointer->Data << ' ';
				pointer = pointer->pNext;
			}
		}
		else if (side ==1){
			pointer = pLast;
			for (int i = 1; i <= N; i++){
				cout << pointer->Data << ' ';
				pointer = pointer->pPrev;
			}
		}
	}

	else{
		cout << "List is empty";
	}
	
	cout << "\n\n";
}


unsigned int C2List::sizeofList()
{
	int i = 0;
	SListElem *pointer = pFirst;	
	
	while (pointer != NULL){
		pointer = pointer->pNext;
		i++;
	}
	return i;
}


void C2List::addElem (unsigned int side, int Data)
{
	int N = sizeofList();
	SListElem *ptemp = new SListElem;
	
	if (N == 0){							// create 1st element
		ptemp->pNext = NULL;
		ptemp->pPrev = NULL;
		ptemp->Data = Data;
		pFirst = ptemp;
		pLast = ptemp;
	}

	else{

		if (side == 0){						// add to the left
			ptemp->Data = Data;
			ptemp->pNext = pFirst;
			ptemp->pPrev = NULL;
			pFirst->pPrev = ptemp;
			pFirst = ptemp;
		}

		else if (side == 1){				// add to the right
			ptemp->Data = Data;
			ptemp->pNext = NULL;
			ptemp->pPrev = pLast;
			pLast->pNext = ptemp;
			pLast = ptemp;
		}
	}
}


void C2List::deleteElem (unsigned int side)
{
	SListElem *ptemp;
	int N = sizeofList();
	
	if (N == 0){
		cout << "Error, List is already empty" << '\n';
	}
	else if (N == 1){
		ptemp = pFirst;
		pFirst = NULL;
		pLast = NULL;
		delete ptemp;
	}
	else{

		if (side == 0){								//delete from left
			ptemp = pFirst;
			pFirst = pFirst->pNext;
			pFirst->pPrev = NULL;
			delete ptemp;
		}
		else if (side == 1){						//delete from right
			ptemp = pLast;
			pLast = pLast->pPrev;
			pLast->pNext = NULL;
			delete ptemp;
		}
	}
}


SListElem* C2List::search (int Data, unsigned int whichone = 1, bool isReverse = 0)
{
	unsigned int N = sizeofList();
	unsigned int counter = 1;
	SListElem* pointer;
	
	if (isReverse == 0){
		pointer = pFirst;
		for (int i = 1; i <= N; i++){

			if ( pointer->Data == Data ){
				if ( counter != whichone ){
					counter++;
				}
				else if (counter == whichone){
					return pointer;
				}
				else{
					cout << '\n' << "Error with counter1" << '\n';
				}
			}

			pointer = pointer->pNext; 
		}

	} 
	else if(isReverse == 1){
		pointer = pLast;
		for (int i = 1; i <= N; i++){

			if (pointer->Data == Data ){
				if ( counter != whichone ){
					counter++;
				}
				else if (counter == whichone){
					return pointer;
				}
				else{
					cout << '\n' << "Error with counter2" << '\n';
				}
			}

			pointer = pointer->pPrev;
		}
	}
	else{
		cout << '\n' << "ERROR: Wrong entering" << '\n';
	}
}


void C2List::createList( unsigned int size )
{
	int Data;
	unsigned int side = 1;
	cout << "Enter Data" << '\n';
	for (int i = 1; i <= size; i++){
		cout << i << ")";
		cin >> Data;
		addElem(side, Data);
	}
}



