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
		void printList();
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
	
}


void C2List::printList()
{
	SListElem *pointer = pFirst;
	int N = sizeofList();
	
	if (N > 0){
		for (int i = 1; i <= N; i++){
			cout << pointer->Data << ' ';
			pointer = pointer->pNext;
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
	
	L1.addElem(1,5);
	L1.addElem(0,4);
	L1.addElem(1,3);
	L1.addElem(0,5);
	L1.addElem(0,7);
	L1.addElem(1,0);
	L1.addElem(1,9);
	
	L1.printList();

	L1.deleteElem(0);
	L1.deleteElem(1);
	L1.deleteElem(0);
	L1.deleteElem(0);
	L1.deleteElem(1);
	L1.deleteElem(1);
	L1.deleteElem(0);
	L1.deleteElem(0);

	L1.printList();

	

	return 0;
}













