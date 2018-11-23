#include <iostream>
using namespace std;

struct SListElem
{
	public:
		int Data;
	private:
		SListElem *pPrev;
		SListElem *pNext;

	friend class C2List;
};

class C2List 
{
	private: 
		SListElem *pFirst;
		SListElem *pLast;
	public:
		C2List();
		~C2List();
		SListElem *getFirst();
		SListElem *getLast();
		unsigned int sizeofList();
		void clearList();
		void printList(unsigned int);
		void addElem(unsigned int, int);
		void deleteElem(unsigned int);
};


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
		<< "5 - to exit" << '\n';
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

