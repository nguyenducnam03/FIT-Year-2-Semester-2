#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

const int SIZE = 100;

struct Date {
	int ngay, thang, nam;
};

class NhanVien
{
protected:
	char maNV[SIZE];
	char hoten[SIZE];
	char diachi[SIZE];
	char gioitinh[SIZE];
	Date ngaysinh;
public:
	NhanVien();

	virtual NhanVien* clone() = 0;

	virtual ~NhanVien();

	virtual float getLuong() = 0;

	virtual void input();
	virtual void print();

	virtual char* getMaNV();
	virtual char* getTenNV();
	/*virtual char* getDiaChi();
	virtual Date getNgaySinh();*/
	virtual char* getGioitinh();
	virtual int getThang();

	//virtual void writeFile(ofstream& fout);
	//virtual void readFile(ifstream& fin);
};



