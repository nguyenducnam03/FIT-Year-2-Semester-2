#pragma once
#include "KhoaHoc.h"
#include "SinhVien.h"
#include "DanhSachSinhVien.h"

class DanhSachSinhVien;

class DangKy
{
protected:

public:
	DangKy();
	~DangKy();
	static void dangky(SinhVien& sv, KhoaHoc& kh);
	static void dangky(SinhVien& sv, DanhSachKhoaHoc& ds, int index);
	static void dangky(DanhSachSinhVien& dssv,const int &index1, DanhSachKhoaHoc& dskh, const int &index2);
};

