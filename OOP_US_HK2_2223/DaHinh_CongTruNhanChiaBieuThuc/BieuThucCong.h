#pragma once
#include "BieuThuc.h"
class BieuThucCong :
    public BieuThuc
{
protected:
    vector<BieuThuc*> ds;
public:
    BieuThucCong();
    ~BieuThucCong();
    virtual void themBieuThuc(BieuThuc* bt);
    virtual float tinhF(int& x);
};

