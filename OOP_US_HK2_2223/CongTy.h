#pragma once
#include "NhanVien.h"
#include "NhanVienCongNhat.h"
#include "NhanVienSanXuat.h"

class CongTy
{
private:
	int size;
	NhanVien** arr;
public:
	CongTy();
	CongTy(const CongTy& vp);
	CongTy& operator =(const CongTy& vp);

	~CongTy();

	void input();
	void print();

	//Thuchiencaccau
	void c1_ghiDSNV(string& fileName);
	void c2_docDSNV(string& fileName);
	void c3_xuatDSNV();
	float c4_getLuong();
	void c5_timNVLuongMax();
	float c6_AVGLuong();
	void c7_timNVtheoMa();
	void c8_timNVtheoTen();
	void c9_timNVSinhThang5(int thang);
	void c10_themvacapnhap(string& fileName);
	void c11_xoavacapnhap(string& fileName);
	void c12_ghiNVLuongThapHonTB(string& fileName);
};


