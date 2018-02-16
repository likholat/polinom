#include "LineList.h"
#include "HeadList.h"
#include "Polinom.h"
#include <iostream>
 
#pragma once

using namespace std;

void main(){
	TList<int> list;
	while (1){
	int a;
	cout << endl;
	cout << "enter the value" << endl;
	cin >> a;
	cout << endl;
	list.Sort(a);
	for (list.Reset(); !list.IsEnd(); list.GoNext()){
		cout << list.GetCurrVal() << " ";
	}
	cout << endl;

}
}