#include "BangPhanCong.h"

BangPhanCong::BangPhanCong() {

}

BangPhanCong::~BangPhanCong() {
	int size = bangphancong.size();
	for (int i = 0; i < size; i++) {
		TenSinhVien temp = bangphancong[bangphancong.size() - 1];
		bangphancong.pop_back();
		delete[] temp.TenSV;
	}
}

void BangPhanCong::print() {
	for (int i = 0; i < bangphancong.size(); i++) {
		cout << bangphancong[i].TenSV << endl;
	}
}