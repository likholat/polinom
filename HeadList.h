#include <iostream>

#include "LineList.h"

#pragma once

template <class T>

class THeadList:public TList<T>{
	protected:
	TLink<T> *pHead;

public:
	THeadList(): TList<T>(){
		TLink<T> *tmp = new TLink<T>;
		pHead = tmp;
		pHead -> pNext = pHead;
		pStop = pHead;
	}

	/*~THeadList(){
		TLink<T>::~TList();
		delete pHead;
	}*/

	virtual void InsFirst(T a){
		TList<T>:: InsFirst(a);
		pHead -> pNext = pFirst;
	}

	virtual void DelFirst(){
		TList<T>::DelFirst();
		pHead -> pNext = pFirst;
	}


};