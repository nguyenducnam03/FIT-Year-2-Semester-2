#pragma once
#include "Header.h"

struct TenSinhVien {
	char* TenSV;
};

class BangPhanCong
{
protected:
	vector<TenSinhVien> bangphancong;
public:
	BangPhanCong();
	~BangPhanCong();

	void print();

	friend class KhoaHoc;
	friend class DangKy;
};

