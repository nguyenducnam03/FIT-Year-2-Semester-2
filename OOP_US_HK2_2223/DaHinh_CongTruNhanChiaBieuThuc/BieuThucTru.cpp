#include "BieuThucTru.h"

BieuThucTru::BieuThucTru() {


}

BieuThucTru::~BieuThucTru() {


}

void BieuThucTru::themBieuThuc(BieuThuc* bt) {
	ds.push_back(bt);
}

float BieuThucTru::tinhF(int& x) {
	float sum = 0;
	for (int i = 0; i < ds.size(); i++) {
		if (i == 0) {
			sum += ds[i]->tinhF(x);
		}
		else {
			sum -= ds[i]->tinhF(x);
		}
	}
	return sum;
}
