#include <iostream>
#include "TMonom.h"

#pragma once

template <class T>

struct TLink{
	T val;
	TLink* pNext;
};

template <class T>

class TList{
protected:
	TLink<T> *pFirst, *pLast, *pPrev, *pCurr, *pStop;
	int Size, Pos;

public:

	TList(){	 //�����������
		pFirst = pLast = pPrev = pCurr = pStop = NULL;
		Size = 0;
		Pos = -1;
	}

	~TList(){
		while (!IsEmpty())
			DelFirst();
	}


	void InsFirst(T a){		//�������� ������ �����
		TLink<T> *tmp = new TLink<T>;
		tmp -> val = a;
		tmp-> pNext = pFirst;
		if (pFirst == pStop){
			pFirst = pLast = pPrev = pCurr = tmp;
			Pos = 0;
		}
		else{
			tmp -> pNext = pFirst;
			pFirst = tmp;
			Pos++;
		}
		Size++;
	}

	void InsCurr(T a){		//�������� ������� �����
		if(pCurr == pFirst)
			InsFirst(a);
		else
			if(pCurr == pStop)
				InsLast(a);
			else{
			TLink<T> *tmp = new TLink<T>;
			tmp -> val = a;
			tmp -> pNext = pCurr;
			pPrev -> pNext = tmp;
			pCurr = tmp;
			Size++;
		}
	}

	void DelFirst(){	//������� ������
		if(Size == 1){
			delete pFirst;
			pFirst = pLast = pPrev = pCurr = pStop;
		}
		else{
			TLink<T>* tmp = pFirst;
			pFirst = pFirst -> pNext;
			delete tmp;
		}
		Size--; Pos--;
	}

	void DelCurr(){		//������� �������
		if(pCurr == pFirst){
			DelFirst();
		}
		else{
			pCurr = pCurr -> pNext;
			delete pPrev ->pNext ;
			pPrev -> pNext = pCurr;
			Size--;
		}
	}

	bool IsEmpty(){		//�������� �� �������
		if(pFirst == pStop)
			return true;
		else
			return false;
	}

	void Reset(){		//��������� �� ������
		pPrev = pCurr = pFirst;
		Pos = 0;
	}

	void GoNext(){		//������� � ����������
	pPrev = pCurr;
	pCurr = pCurr -> pNext;
	Pos++;
	}

	bool IsEnd(){		//�����
		if(pCurr == pStop)
			return true;
		else
			return false;
	}

	void InsLast(T a){		//�������� ��������� �����
		if (Size == 0){
			InsFirst(a);
		}
		else{
			TLink<T> *tmp = new TLink<T>;
			tmp -> val = a;
			tmp -> pNext = pStop;
			if(pFirst == pStop){
				pFirst = pLast = pCurr = tmp;
				Pos = 0;
			}
			else{
			pLast -> pNext = tmp;
			pLast = tmp;
			}
			Size++;
		}
	}

	T GetCurrVal(){
		return pCurr -> val;
	}

	void Sort (T a){	//����������
	if(IsEmpty()){
		InsFirst(a);
		return;
	}
	if(a < pFirst -> val){
		InsFirst(a);
		return;
	}
	if(a > pLast -> val){
		InsLast(a);
		return;
	}
	for (Reset(); !IsEnd(); GoNext())
		if(pCurr -> val > a ){
			InsCurr(a);	
			return;
		}
	}

	/*void DelLast(){		//������� ��������� �������
		if(pFirst == pLast){
			DelFirst();
		}
		else{
			TLink<T> *tmp = new TLink<T>;
			tmp = pLast;
			pCurr = pCurr -> pNext;
			delete pPrev ->pNext ;
			pPrev -> pNext = pCurr;
			Size--;
		}
	}*/


	void InsMonom (TMonom monom){
		for (Reset(); IsEnd(); GoNext()){
			if (monom == pCurr -> val){
				pCurr -> val.coeff += monom.coeff;
				if (pCurr -> val.coeff == 0)
					DelCurr();
				return;
			}
			else{
				if (monom > pCurr -> val){
					InsCurr(monom);
					return;
				}
			}
		}
	}

};
