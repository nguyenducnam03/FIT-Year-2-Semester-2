#pragma once
#include "BieuThuc.h"
class BieuThucTru :
    public BieuThuc
{
protected:
    vector<BieuThuc*> ds;
public:
    BieuThucTru();
    ~BieuThucTru();
    virtual void themBieuThuc(BieuThuc* bt);
    virtual float tinhF(int& x);
};

