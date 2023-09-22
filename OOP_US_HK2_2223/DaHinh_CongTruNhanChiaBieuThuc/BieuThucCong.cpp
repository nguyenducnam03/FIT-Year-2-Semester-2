#include "BieuThucCong.h"

BieuThucCong::BieuThucCong(){

}

BieuThucCong::~BieuThucCong(){

}

void BieuThucCong::themBieuThuc(BieuThuc* bt){
	ds.push_back(bt);	
}

float BieuThucCong::tinhF(int& x){
	float sum = 0;
	for (int i = 0; i < ds.size(); i++) {
		sum += ds[i]->tinhF(x);
	}
	return sum;
}
