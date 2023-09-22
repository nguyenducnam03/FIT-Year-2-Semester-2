#pragma once
#include "Header.h"

struct Monhoc {
	char* TenMH;
};

class LichBieu
{
protected:
	vector<Monhoc> lichbieu;
public:
	LichBieu();
	~LichBieu();

	void print();

	friend class SinhVien;
	friend class DangKy;
};

