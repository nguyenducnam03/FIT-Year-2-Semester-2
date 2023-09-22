#pragma once
#include "Header.h"
#include "SinhVien.h"
class DanhSachSinhVien
{
protected:
	vector<SinhVien*> danhsach;
public:
	DanhSachSinhVien();
	~DanhSachSinhVien();

	//Chi quan ly cac thong tin co ban cua sinh vien
	//con lich bieu thi co trong lich bieu cua moi sinh vien
	void inputDanhSach(string& fileName);
	void outputDanhSach(string& fileName);

	void thoikhoabieu();

	friend class DangKy;
};

