//#ifndef CList_
//#define CList_

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

//#endif
