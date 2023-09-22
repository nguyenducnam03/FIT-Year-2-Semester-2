#pragma once
#include "BieuThuc.h"
class BieuThucNhan :
    public BieuThuc
{
protected:
    vector<BieuThuc*> ds;
public:
    BieuThucNhan();
    ~BieuThucNhan();
    virtual void themBieuThuc(BieuThuc* bt);
    virtual float tinhF(int& x);
};

