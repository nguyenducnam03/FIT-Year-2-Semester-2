#pragma once
#include "BieuThuc.h"
class Heso :public BieuThuc
{
protected:
	int heso;
public:
	virtual float tinhF(int& x);
};

