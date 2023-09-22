#include "KhoaHoc.h"

KhoaHoc::KhoaHoc() {
	MaKH = new char[100]();
	TenKH = new char[100]();
}

KhoaHoc::~KhoaHoc() {
	if (MaKH != NULL) {
		delete[] MaKH;
	}
	if (TenKH != NULL) {
		delete[] TenKH;
	}
}

bool KhoaHoc::operator == (const KhoaHoc& vp) {
	if ((this->MaKH != vp.MaKH)||
		(this->TenKH != vp.TenKH)||
		(this->lichhoc.ngay != vp.lichhoc.ngay) ||
		(this->lichhoc.thang != vp.lichhoc.thang) ||
		(this->lichhoc.nam != vp.lichhoc.nam)){
		return false;
	}
	return true;
}

//void KhoaHoc::InputDanhSachKhoaHoc(string& fileName) {
//
//}
//
//void KhoaHoc::OutputDanhSachKhoaHoc(string& fileName){
//
//}

void KhoaHoc::print() {
	cout << MaKH << endl;
	cout << TenKH << endl;
	cout << lichhoc.ngay << endl;
	cout << lichhoc.thang << endl;
	cout << lichhoc.nam << endl;
}

void KhoaHoc::sinhviencuakhoahoc() {
	cout << "CAC SINH VIEN DANG KY KHOA HOC NAY!!" << endl;
	this->print();
	cout << "Cac sinh vien: " << endl;
	this->bangphancong.print();
	cout << endl;
}


