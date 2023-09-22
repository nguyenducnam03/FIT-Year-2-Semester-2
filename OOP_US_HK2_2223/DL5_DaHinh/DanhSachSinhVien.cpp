#include "DanhSachSinhVien.h"

DanhSachSinhVien::DanhSachSinhVien() {

}

DanhSachSinhVien::~DanhSachSinhVien() {
	SinhVien* temp;
	int size = danhsach.size();
	for (int i = 0; i < size; i++) {
		temp = danhsach[danhsach.size() - 1];
		/*delete[] temp->MaKH;
		delete[] temp->TenKH;*/
		temp->~SinhVien();
		danhsach.pop_back();
	}
}

void DanhSachSinhVien::inputDanhSach(string& fileName) {
	fstream myFile;
	myFile.open(fileName, ios::in);
	if (myFile.is_open()) {
		int size;
		myFile >> size;
		SinhVien* temp;
		for (int i = 0; i < size; i++) {
			temp = new SinhVien();
			myFile >> temp->MaSV;
			myFile.ignore();
			myFile.getline(temp->TenSV, 100);
			myFile.getline(temp->DiaChi, 100);
			myFile >> temp->ngaysinh.ngay >> temp->ngaysinh.thang >> temp->ngaysinh.nam;
			this->danhsach.push_back(temp);
		}
		myFile.close();
	}
	else {
		cout << "File can't open" << endl;
	}
}

void DanhSachSinhVien::outputDanhSach(string& fileName) {
	fstream myFile;
	myFile.open(fileName, ios::out);
	if (myFile.is_open()) {
		myFile << this->danhsach.size() << endl;
		for (int i = 0; i < this->danhsach.size(); i++) {
			myFile << this->danhsach[i]->MaSV << endl;
			myFile << this->danhsach[i]->TenSV << endl;
			myFile << this->danhsach[i]->DiaChi << endl;
			myFile << this->danhsach[i]->ngaysinh.ngay << endl;
			myFile << this->danhsach[i]->ngaysinh.thang << endl;
			myFile << this->danhsach[i]->ngaysinh.nam << endl;
		}
		myFile.close();
	}
	else {
		cout << "File can't open" << endl;
	}
}

void DanhSachSinhVien::thoikhoabieu() {
	for (int i = 0; i < danhsach.size(); i++) {
		danhsach[i]->thoikhoabieu();
	}
}


