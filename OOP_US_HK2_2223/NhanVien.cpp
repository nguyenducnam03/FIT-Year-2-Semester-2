#include "NhanVien.h"

NhanVien::NhanVien() {

}

NhanVien::~NhanVien() {

}

void NhanVien::input() {
	cout << "Nhap maNV: " << endl;
	cin.getline(maNV, SIZE);
	while (strlen(maNV) != 5) {
		cout << "Chuoi phai 5 ky tu!!" << endl;
		cout << "Nhap lai maNV: " << endl;
		cin.getline(maNV, SIZE);
	}
	bool T = true;
	while (T) {
		for (int i = 0; i < 5; i++) {
			if (maNV[i] < '0' || maNV[i]>'9') {
				cout << "Chuoi phai gom 5 ky tu so!!!" << endl;
				break;
			}
			else if (i == 4) {
				T = false;
			}
		}
		if (T) {
			cout << "Nhap lai maNV: " << endl;
			cin.getline(maNV, SIZE);
		}
	}

	cout << "Nhap hoten: " << endl;
	cin.getline(hoten, SIZE);
	cout << "Nhap diachi: " << endl;
	cin.getline(diachi, SIZE);
	cout << "Nhap gioi tinh (Nam - Nu): " << endl;
	cin.getline(gioitinh, SIZE);
	while (strcmp(gioitinh, "Nam") != 0 && strcmp(gioitinh, "Nu") != 0) {
		cout << "Gioi tinh hoac Nam hoac Nu!!!" << endl;
		cout << "Nhap lai gioi tinh (Nam - Nu): " << endl;
		cin.getline(gioitinh, SIZE);
	}
	cout << "Nhap ngay sinh. " << endl;
	cout << "Nhap ngay: "; cin >> ngaysinh.ngay;
	cout << "Nhap thang: "; cin >> ngaysinh.thang;
	cout << "Nhap nam: "; cin >> ngaysinh.nam;
	if (strcmp(gioitinh, "Nam") == 0) {
		while (2023 - ngaysinh.nam < 18 || 2023 - ngaysinh.nam >60) {
			cout << "Tuoi NV Nam phai tu 18-60!!!" << endl;
			cout << "Nhap lai ngay sinh. " << endl;
			cout << "Nhap ngay: "; cin >> ngaysinh.ngay;
			cout << "Nhap thang: "; cin >> ngaysinh.thang;
			cout << "Nhap nam: "; cin >> ngaysinh.nam;
		}
	}
	else {
		while (2023 - ngaysinh.nam < 18 || 2023 - ngaysinh.nam >55) {
			cin.ignore();
			cout << "Tuoi NV Nam phai tu 18-55!!!" << endl;
			cout << "Nhap lai ngay sinh. " << endl;
			cout << "Nhap ngay: "; cin >> ngaysinh.ngay;
			cout << "Nhap thang: "; cin >> ngaysinh.thang;
			cout << "Nhap nam: "; cin >> ngaysinh.nam;
		}
	}
}

void NhanVien::print() {
	cout << "=============Xuat nhan vien.===========" << endl;
	cout << "Xuat maNV: " << maNV << endl;
	cout << "Xuat hoten: " << hoten << endl;
	cout << "Xuat diachi: " << diachi << endl;
	cout << "Xuat gioitinh: " << gioitinh << endl;
	cout << "Xuat ngay sinh. " << endl;
	cout << ngaysinh.ngay << "/" << ngaysinh.thang
		<< "/" << ngaysinh.nam << endl;
}

char* NhanVien::getMaNV() {
	return maNV;
}

char* NhanVien::getTenNV() {
	return hoten;
}

char* NhanVien::getGioitinh() {
	return gioitinh;
}

int NhanVien::getThang() {
	return ngaysinh.thang;
}

//char* NhanVien::getDiaChi(){
//	return diachi;
//}

//Date NhanVien::getNgaySinh(){
//	return ngaysinh;
//}


//void NhanVien::writeFile(ofstream& fout) {
//	fout.write((char*)this, sizeof(NhanVien));
//}
//
//void NhanVien::readFile(ifstream& fin) {
//	fin.read((char*)this, sizeof(NhanVien));
//}

