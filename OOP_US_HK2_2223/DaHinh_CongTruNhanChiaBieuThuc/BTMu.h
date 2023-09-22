#pragma once
#include "BieuThuc.h"
class BTMu :
    public BieuThuc
{
protected:
    int bac;
public:
    virtual float tinhF(int& x);
};

