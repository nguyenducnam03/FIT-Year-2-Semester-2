#pragma once
#include "NhanVien.h"
class NhanVienCongNhat :
	public NhanVien
{
protected:
	int songay;
public:
	NhanVienCongNhat();
	NhanVien* clone();

	~NhanVienCongNhat();

	float getLuong();
	void input();
	void print();

	char* getMaNV();
	char* getTenNV();
	char* getGioitinh();
	int getThang();

	//void writeFile(ofstream& fout);
	//void readFile(ifstream& fin);
};

