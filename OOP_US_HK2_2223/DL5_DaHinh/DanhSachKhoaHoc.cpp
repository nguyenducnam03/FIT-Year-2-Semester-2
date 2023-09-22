#include "DanhSachKhoaHoc.h"

DanhSachKhoaHoc::DanhSachKhoaHoc(){

}

DanhSachKhoaHoc::~DanhSachKhoaHoc(){
	KhoaHoc* temp;
	int size = danhsach.size();
	for (int i = 0; i < size; i++) {
		temp = danhsach[danhsach.size() - 1];
		/*delete[] temp->MaKH;
		delete[] temp->TenKH;*/
		temp->~KhoaHoc();
		danhsach.pop_back();
	}
}

void DanhSachKhoaHoc::inputDanhSach(string& fileName) {
	fstream myFile;
 	myFile.open(fileName, ios::in);
	if (myFile.is_open()) {
		int size;
		myFile >> size;
		KhoaHoc* temp;
		for (int i = 0; i < size; i++) {
			temp = new KhoaHoc();
			myFile >> temp->MaKH;
			myFile.ignore();
			myFile.getline(temp->TenKH, 100);
			myFile >> temp->lichhoc.ngay >> temp->lichhoc.thang >> temp->lichhoc.nam;
			this->danhsach.push_back(temp);
		}

		myFile.close();
	}
	else {
		cout << "File can't open" << endl;
	}
}

void DanhSachKhoaHoc::outputDanhSach(string& fileName){
	fstream myFile;
	myFile.open(fileName, ios::out);
	if (myFile.is_open()) {
		myFile << this->danhsach.size() << endl;
		for (int i = 0; i < this->danhsach.size(); i++) {
			myFile << this->danhsach[i]->MaKH << endl;
			myFile << this->danhsach[i]->TenKH << endl;
			myFile << this->danhsach[i]->lichhoc.ngay << endl;
			myFile << this->danhsach[i]->lichhoc.thang << endl;
			myFile << this->danhsach[i]->lichhoc.nam << endl;
		}
		myFile.close();
	}
	else {
		cout << "File can't open" << endl;
	}
}

void DanhSachKhoaHoc::print() {
	cout << "So luong mon: ";
	cout << this->danhsach.size() << endl;
	for (int i = 0; i < this->danhsach.size(); i++) {
		cout << "Mon "<< i+1 <<":" << endl;
		cout << this->danhsach[i]->MaKH << endl;
		cout << this->danhsach[i]->TenKH << endl;
		cout << this->danhsach[i]->lichhoc.ngay<<" / "
			<< this->danhsach[i]->lichhoc.thang <<" / "
		<< this->danhsach[i]->lichhoc.nam << endl;
		cout << "=================================" << endl;
	}
}

void DanhSachKhoaHoc::sinhviencuakhoahoc() {
	for (int i = 0; i < danhsach.size(); i++) {
		danhsach[i]->sinhviencuakhoahoc();
	}
}

