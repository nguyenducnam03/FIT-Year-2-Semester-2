#include "CongTy.h"

CongTy::CongTy() {
	size = 0;
	arr = NULL;
}

CongTy::CongTy(const CongTy& vp) {
	size = vp.size;
	arr = new NhanVien * [size];
	for (int i = 0; i < size; i++) {
		arr[i] = vp.arr[i]->clone();
	}
}

CongTy& CongTy::operator =(const CongTy& vp) {
	if (this != &vp) {
		this->~CongTy();
		size = vp.size;
		arr = new NhanVien * [size];
		for (int i = 0; i < size; i++) {
			arr[i] = vp.arr[i]->clone();
		}
	}
	return *this;
}


CongTy::~CongTy() {
	for (int i = 0; i < size; i++) {
		arr[i]->~NhanVien();
	}
	if (arr != NULL) {
		delete[] arr;
	}
	size = 0;
}

void CongTy::input() {
	this->~CongTy();
	cout << "Nhap so luong nhan vien:";
	cin >> size;
	if (size <= 0) {
		return;
	}
	arr = new NhanVien * [size];
	int type;
	for (int i = 0; i < size; i++) {
		cout << endl << "Nhap nhan vien " << i + 1 << ": " << endl;
		cout << "Chon loai Nhan vien: " << endl;
		cout << "1. San Xuat." << endl
			<< "2. Cong Nhat." << endl;
		cin >> type;
		while (type < 1 || type>2) {
			cout << "Chon sai, chon lai." << endl;
			cout << "Chon loai nhan vien: " << endl;
			cout << "1. San Xuat." << endl
				<< "2. Cong Nhat." << endl;
			cin >> type;
		}
		cin.ignore();
		if (type == 1) {
			arr[i] = new NhanVienSanXuat();
				arr[i]->input();

		}
		else {
			arr[i] = new NhanVienCongNhat();
			arr[i]->input();
		}
	}
	this->size = size;
}

void CongTy::print() {
	for (int i = 0; i < size; i++) {
		arr[i]->print();
	}
}

void CongTy::c1_ghiDSNV(string& fileName) {
	ofstream fout(fileName, ios::binary);
	if (fout.is_open()) {
		int size = this->size;
		fout.write((char*)(&size), sizeof(size));
		int type;
		for (int i = 0; i < size; i++) {
			if (dynamic_cast<NhanVienSanXuat*>(arr[i])) {
				type = 1;
				fout.write((char*)(&type), sizeof(int));
				fout.write((char*)arr[i], sizeof(NhanVienSanXuat));
			}
			else {
				type = 2;
				fout.write((char*)(&type), sizeof(int));
				fout.write((char*)arr[i], sizeof(NhanVienCongNhat));
			}
		}
	}
	else {
		cout << "File cann't open" << endl;
	}
	
}

void CongTy::c2_docDSNV(string &fileName) {
	this->~CongTy();
	ifstream fin(fileName, ios::in);
	if (fin.is_open()) {
		int size;
		fin.read((char*)(&size), sizeof(int));
		this->size = size;
		arr = new NhanVien * [size];
		int type;
		for (int i = 0; i < size; i++) {
			fin.read((char*)(&type), sizeof(int));
			if (type == 1) {
				NhanVienSanXuat temp;
				fin.read((char*)&temp, sizeof(NhanVienSanXuat));
				arr[i] = temp.clone();
			}
			else {
				NhanVienCongNhat temp;
				fin.read((char*)&temp, sizeof(NhanVienCongNhat));
				arr[i] = temp.clone();
			}
		}
	}
	else {
		cout << "File cann't open" << endl;
	}
	
}

void CongTy::c3_xuatDSNV() {
	cout << "Xuat danh sach nhan vien ra man hinh: ======" << endl;
	this->print();
	cout << endl;
}

float CongTy::c4_getLuong() {
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i]->getLuong();
	}
	return sum;
}

void CongTy::c5_timNVLuongMax() {
	if (size <= 0) {
		cout << "Khong co nhan vien nao" << endl;
		return;
	}
	int idx = 0;
	float max = arr[0]->getLuong();
	for (int i = 1; i < size; i++) {
		if (arr[i]->getLuong() > max) {
			idx = i;
			max = arr[i]->getLuong();
		}
	}
	cout << "Nhan vien luong cao nhat:" << endl;
	arr[idx]->print();
}

float CongTy::c6_AVGLuong() {
	return c4_getLuong() / size;
}

void CongTy::c7_timNVtheoMa() {
	cout << "Nhap ma NV de tim:" << endl;
	char* temp = new char[100]();
	cin.getline(temp, 100);
	for (int i = 0; i < size; i++) {
		if (strcmp(temp, arr[i]->getMaNV()) == 0) {
			arr[i]->print();
		}
	}
}

void CongTy::c8_timNVtheoTen() {
	cout << "Nhap ten NV de tim:" << endl;
	char* temp = new char[100]();
	cin.getline(temp, 100);
	for (int i = 0; i < size; i++) {
		if (strcmp(temp, arr[i]->getTenNV()) == 0) {
			arr[i]->print();
		}
	}
}

void CongTy::c9_timNVSinhThang5(int thang) {
	for (int i = 0; i < size; i++) {
		if (arr[i]->getThang() == thang) {
			arr[i]->print();
		}
	}
}

void CongTy::c10_themvacapnhap(string& fileName) {
	cout << "Them nhan vien vao danh sach." << endl;
	CongTy vp = *this;
	this->~CongTy();
	size = vp.size + 1;
	arr = new NhanVien * [size];
	for (int i = 0; i < size - 1; i++) {
		if (dynamic_cast<NhanVienSanXuat*>(vp.arr[i])) { //Check if here is NhanVienSanXuat
			arr[i] = vp.arr[i]->clone();
		}
		else {
			arr[i] = vp.arr[i]->clone();
		}
	}

	int type;
	cout << "Chon loai Nhan vien: " << endl;
	cout << "1. San Xuat." << endl
		<< "2. Cong Nhat." << endl;
	cin >> type;
	while (type < 1 || type>2) {
		cout << "Chon sai, chon lai." << endl;
		cout << "Chon loai nhan vien: " << endl;
		cout << "1. San Xuat." << endl
			<< "2. Cong Nhat." << endl;
		cin >> type;
	}
	cin.ignore();
	if (type == 1) {
		arr[size - 1] = new NhanVienSanXuat();
		arr[size - 1]->input();
	}
	else {
		arr[size - 1] = new NhanVienCongNhat();
		arr[size - 1]->input();
	}
	this->c1_ghiDSNV(fileName);
}

void CongTy::c11_xoavacapnhap(string& fileName) {
	int idx;
	cout << "Chon vi tri nhan vien muon xoa (1-->" << size << "): " << endl;
	cin >> idx;
	if (idx <= 0 || idx > size) {
		cout << "Khong xoa." << endl;
		return;
	}
	cout << "Xoa nhan vien." << endl;
	CongTy vp = *this;
	this->~CongTy();
	size = vp.size - 1;;
	arr = new NhanVien * [size];
	int k = 0;
	for (int i = 0; i < vp.size; i++) {
		if (i + 1 == idx) {
			k = 1;
			continue;
		}
		if (dynamic_cast<NhanVienSanXuat*>(vp.arr[i])) { //Check if here is NhanVienSanXuat
			arr[i - k] = vp.arr[i]->clone();
		}
		else {
			arr[i - k] = vp.arr[i]->clone();
		}
	}

	this->c1_ghiDSNV(fileName);
}

void CongTy::c12_ghiNVLuongThapHonTB(string& fileName){
	cout << "Ghi cac nhan vien co luong thap hon trung binh." << endl;
	cout << "Luong trinh binh: " << this->c6_AVGLuong() << endl;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i]->getLuong() < this->c6_AVGLuong()) {
			count++;
		}
	}
	ofstream fout(fileName, ios::binary);
	if (fout.is_open()) {
		fout.write((char*)(&count), sizeof(count));
		int type;
		for (int i = 0; i < size; i++) {
			if (arr[i]->getLuong() < this->c6_AVGLuong()) {
				if (dynamic_cast<NhanVienSanXuat*>(arr[i])) {
					type = 1;
					fout.write((char*)(&type), sizeof(int));
					fout.write((char*)arr[i], sizeof(NhanVienSanXuat));
				}
				else {
					type = 2;
					fout.write((char*)(&type), sizeof(int));
					fout.write((char*)arr[i], sizeof(NhanVienCongNhat));
				}
			}
		}
	}
	else {
		cout << "File cann't open" << endl;
	}

}
