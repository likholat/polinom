#include <iostream>

#include "TMonom.h"
#include "HeadList.h"

class TPolinom:public THeadList<TMonom>{
public: 

	TPolinom():THeadList <TMonom>(){
		pHead -> val.coeff = 0;
		pHead -> val.z = -1;
	}

	TPolinom(TMonom *m, int size):THeadList<TMonom>(){
		pHead -> val.coeff = 0;
		pHead -> val.z = -1;
		for (int i = 0; i < size; i++)
			InsMonom(m[i]);
	}

};

