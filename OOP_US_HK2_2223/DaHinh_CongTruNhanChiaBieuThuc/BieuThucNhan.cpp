#include "BieuThucNhan.h"

BieuThucNhan::BieuThucNhan() {


}

BieuThucNhan::~BieuThucNhan() {


}

void BieuThucNhan::themBieuThuc(BieuThuc* bt) {
	ds.push_back(bt);
}

float BieuThucNhan::tinhF(int& x) {
	float sum = 1;
	for (int i = 0; i < ds.size(); i++) {
		sum *= ds[i]->tinhF(x);
	}
	if (ds.size() == 0) {
		return 0;
	}
	else {
		return sum;
	}
}
