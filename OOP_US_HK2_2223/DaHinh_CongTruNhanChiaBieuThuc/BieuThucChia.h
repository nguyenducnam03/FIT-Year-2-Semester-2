#pragma once
#include "BieuThuc.h"
class BieuThucChia :
    public BieuThuc
{
protected:
    vector<BieuThuc*> ds;
public:
    BieuThucChia();
    ~BieuThucChia();
    virtual void themBieuThuc(BieuThuc* bt);
    virtual float tinhF(int& x);
};

