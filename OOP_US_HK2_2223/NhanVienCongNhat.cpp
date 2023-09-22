#include "NhanVienCongNhat.h"
NhanVienCongNhat::NhanVienCongNhat() :NhanVien() {

}

NhanVienCongNhat::~NhanVienCongNhat() {

}

NhanVien* NhanVienCongNhat::clone() {
	NhanVienCongNhat* p = new NhanVienCongNhat();
	if (p == NULL) return NULL;
	strcpy_s(p->maNV, 100, this->maNV);
	strcpy_s(p->hoten, 100, this->hoten);
	strcpy_s(p->diachi, 100, this->diachi);
	strcpy_s(p->gioitinh, 100, this->gioitinh);
	p->ngaysinh = this->ngaysinh;
	p->songay = this->songay;
	return p;
}

float NhanVienCongNhat::getLuong() {
	return 500000 * songay;
}

void NhanVienCongNhat::input() {
	cout << "====Input NhanVienCongNhat====" << endl;
	NhanVien::input();
	cout << "Nhap so ngay: ";
	cin >> songay;
	while (songay < 22 || songay>26) {
		cout << "So ngay phai tu 22-26!!!" << endl;
		cout << "Nhap lai so ngay: ";
		cin >> songay;
	}
}

void NhanVienCongNhat::print() {
	cout << "=====Print NhanVienCongNhat=====" << endl;
	NhanVien::print();
	cout << "So san pham: " << songay << endl;
	cout << "Luong: " << getLuong() << endl;
}

char* NhanVienCongNhat::getMaNV() {
	return NhanVien::getMaNV();
}

char* NhanVienCongNhat::getTenNV() {
	return NhanVien::getTenNV();
}

char* NhanVienCongNhat::getGioitinh() {
	return NhanVien::getGioitinh();
}

int NhanVienCongNhat::getThang() {
	return NhanVien::getThang();
}

//void NhanVienCongNhat::writeFile(ofstream& fout) {
//	NhanVien::writeFile(fout);
//	fout.write((char*)&songay, sizeof(int));
//}
//
//void NhanVienCongNhat::readFile(ifstream& fin) {
//	NhanVien::readFile(fin);
//	fin.read((char*)&songay, sizeof(int));
//}

