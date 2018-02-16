#include <iostream>

#pragma once

struct TMonom{

	double coeff;
	int x, y, z;
};

bool operator < (const TMonom& p, const TMonom& q){

	if (p.x < q.x)
		return true;
	if (p.x == q.x){
		if (p.y < q.y)
			return true;
		if (p.y == q.y){
			if (p.z < q.z)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool operator > (const TMonom& p, const TMonom& q){

	if (p.x > q.x)
		return true;
	if (p.x == q.x){
		if (p.y > q.y)
			return true;
		if (p.y == q.y){
			if (p.z > q.z)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool operator == (const TMonom& p, const TMonom& q){

	if (p.x == q.x){
		if(p.y == q.y){
			if (p.z == q.z)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool operator != (const TMonom& p, const TMonom& q){

	if (p.x != q.x)
		return true;
	if (p.y != q.y)
		return true;
	if (p.z != q.z)
		return true;
	return false;
}
