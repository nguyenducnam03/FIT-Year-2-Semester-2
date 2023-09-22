#pragma once
#include "Header.h"
#include "KhoaHoc.h"
class DanhSachKhoaHoc
{
protected:
	vector<KhoaHoc*> danhsach;
public:
	DanhSachKhoaHoc();
	~DanhSachKhoaHoc();

	//Chi quan ly cac thong tin co ban cua khoa hoc
	//con thong tin khoa hoc co bao nhieu hoc sinh thi trong file bangphancong
	void inputDanhSach(string &fileName);
	void outputDanhSach(string& fileName);

	void print();

	void sinhviencuakhoahoc();

	friend class DangKy;
};

