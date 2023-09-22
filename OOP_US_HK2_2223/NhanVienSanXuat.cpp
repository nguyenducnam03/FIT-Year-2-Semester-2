#include "NhanVienSanXuat.h"
NhanVienSanXuat::NhanVienSanXuat() :NhanVien() {

}

NhanVienSanXuat::~NhanVienSanXuat() {

}

NhanVien* NhanVienSanXuat::clone() {
	NhanVienSanXuat* p = new NhanVienSanXuat();
	if (p == NULL) return NULL;
	strcpy_s(p->maNV, SIZE, this->maNV);
	strcpy_s(p->hoten, SIZE, this->hoten);
	strcpy_s(p->diachi, SIZE, this->diachi);
	strcpy_s(p->gioitinh, SIZE, this->gioitinh);
	p->ngaysinh = this->ngaysinh;
	p->sosanpham = this->sosanpham;
	return p;
}

float NhanVienSanXuat::getLuong() {
	return 50000 * 30 * sosanpham;
}

void NhanVienSanXuat::input() {
	cout << "====Input NhanVienSanXuat====" << endl;
	NhanVien::input();
	cout << "Nhap san pham: ";
	cin >> sosanpham;
	while (sosanpham < 10 || sosanpham>15) {
		cout << "So san pham phai tu 10-15!!!" << endl;
		cout << "Nhap lai so san pham: ";
		cin >> sosanpham;
	}
}

void NhanVienSanXuat::print() {
	cout << "=====Print NhanVienSanXuat=====" << endl;
	NhanVien::print();
	cout << "So san pham: " << sosanpham << endl;
	cout << "Luong: " << getLuong() << endl;
}

char* NhanVienSanXuat::getMaNV() {
	return NhanVien::getMaNV();
}

char* NhanVienSanXuat::getTenNV() {
	return NhanVien::getTenNV();
}

char* NhanVienSanXuat::getGioitinh() {
	return NhanVien::getGioitinh();
}

int NhanVienSanXuat::getThang() {
	return NhanVien::getThang();
}

//char* NhanVienSanXuat::getDiaChi(){
//	return NhanVien::getDiaChi();
//}
//
//Date NhanVienSanXuat::getNgaySinh(){
//	return NhanVien::getNgaySinh();
//}


//void NhanVienSanXuat::writeFile(ofstream& fout) {
//	/*NhanVien::writeFile(fout);
//	fout.write((char*)&sosanpham, sizeof(int));*/
//	fout.write((char*)this, sizeof(NhanVienSanXuat));
//}
//
//void NhanVienSanXuat::readFile(ifstream& fin) {
//	/*NhanVien::readFile(fin);
//	fin.read((char*)&sosanpham, sizeof(int));*/
//	this->~NhanVienSanXuat();
//	fin.read((char*)this, sizeof(NhanVienSanXuat));
//}