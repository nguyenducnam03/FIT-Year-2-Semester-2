#include "BieuThucChia.h"

BieuThucChia::BieuThucChia() {


}

BieuThucChia::~BieuThucChia() {


}

void BieuThucChia::themBieuThuc(BieuThuc* bt) {
	ds.push_back(bt);
}

float BieuThucChia::tinhF(int& x) {
	float sum = 0;
	for (int i = 0; i < ds.size(); i++) {
		sum += ds[i]->tinhF(x);
	}
	return sum;
}
