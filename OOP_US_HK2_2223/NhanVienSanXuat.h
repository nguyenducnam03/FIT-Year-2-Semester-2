#pragma once
#include "NhanVien.h"
class NhanVienSanXuat :
	public NhanVien
{
protected:
	int sosanpham;
public:
	NhanVienSanXuat();
	NhanVien* clone();

	~NhanVienSanXuat();

	float getLuong();
	void input();
	void print();

	char* getMaNV();
	char* getTenNV();
	char* getGioitinh();
	/*char* getDiaChi();
	Date getNgaySinh();*/
	int getThang();

	/*void writeFile(ofstream& fout);
	void readFile(ifstream& fin);*/
};


