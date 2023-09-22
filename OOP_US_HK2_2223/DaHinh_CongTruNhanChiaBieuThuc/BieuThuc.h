#pragma once
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
class BieuThuc
{
protected:

public:
	BieuThuc();
	~BieuThuc();
	virtual void themBieuThuc(BieuThuc* bt) = 0;
	virtual float tinhF(int &x) = 0;
};

