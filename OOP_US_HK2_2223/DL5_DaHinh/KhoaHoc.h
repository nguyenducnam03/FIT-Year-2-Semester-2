#pragma once
#include "Header.h"
#include "BangPhanCong.h"

struct LichHoc {
	int ngay, thang, nam;
};

class KhoaHoc
{
protected:
	char* MaKH;
	char* TenKH;
	LichHoc lichhoc;
	BangPhanCong bangphancong;
public:
	KhoaHoc();
	~KhoaHoc();

	//Check if two KhoaHocs are the same
	bool operator == (const KhoaHoc &vp);

	void print();

	void sinhviencuakhoahoc();

	friend class DanhSachKhoaHoc;
	friend class DangKy;
};

