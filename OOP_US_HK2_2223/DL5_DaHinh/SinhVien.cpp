#include "SinhVien.h"

SinhVien::SinhVien() {
	MaSV = new char[100]();
	TenSV = new char[100]();
	DiaChi = new char[100]();
}

SinhVien::~SinhVien(){
	if (MaSV != NULL) {
		delete[]MaSV;
	}

	if(TenSV!=NULL){
		delete[]TenSV;
	}

	if(DiaChi!=NULL){
		delete[]DiaChi;
	}
}

void SinhVien::input() {
	cout << "Nhap MaSV:";
	cin >> MaSV;
	cin.ignore();
	cout << "Ten MaSV:";
	cin.getline(TenSV, 100);
	cout << "Nhap Dia chi:";
	cin.getline(DiaChi, 100);
	cout << "Nhap ngay:";
	cin >> ngaysinh.ngay;
	cout << "Nhap thang:";
	cin >> ngaysinh.thang;
	cout << "Nhap nam:";
	cin >> ngaysinh.nam;
}

void SinhVien::print() {
	cout << MaSV << endl;
	cout << TenSV << endl;
	cout << DiaChi << endl;
	cout << ngaysinh.ngay << " / "
		<< ngaysinh.thang << " / "
		<< ngaysinh.nam << endl;
}

void SinhVien::dangkymonhoc(DanhSachKhoaHoc &ds) {
	//in danh sach khoa hoc truoc
	ds.print();
	int luachon=-1;
	while (luachon != 0) {
		cout << "Ban muon dang ky mon so (0=exit): ";
		cin >> luachon;
		DangKy::dangky(*this, ds, luachon);
	}
}

void SinhVien::thoikhoabieu() {
	cout << "THOI KHOA BIEU SINH VIEN." << endl;
	this->print();
	cout << "Cac mon hoc: " << endl;
	this->TKB.print();
	cout << endl;
}