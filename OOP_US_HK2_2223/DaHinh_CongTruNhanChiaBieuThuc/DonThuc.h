#pragma once
#include "BieuThuc.h"
class DonThuc :
    public BieuThuc
{
protected:
    int heso;
    int somu;
public:
    DonThuc();
    DonThuc(const int&);
    DonThuc(const int&, const int&);
    ~DonThuc();
    virtual void themBieuThuc(BieuThuc* bt);
    virtual float tinhF(int& x);
};

