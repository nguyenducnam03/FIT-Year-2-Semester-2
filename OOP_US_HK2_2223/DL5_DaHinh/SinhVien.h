#pragma once
#include "Header.h"
#include "LichBieu.h"
#include "DanhSachKhoaHoc.h"
#include "DangKy.h"

struct NgaySinh {
	int ngay, thang, nam;
};

class SinhVien
{
protected:
	char* MaSV;
	char* TenSV;
	char* DiaChi;
	NgaySinh ngaysinh;
	LichBieu TKB;
public:
	SinhVien();
	~SinhVien();

	void input();
	void print();
	void dangkymonhoc(DanhSachKhoaHoc &ds);

	void thoikhoabieu();

	friend class DanhSachSinhVien;
	friend class DangKy;
};

