#include "DangKy.h"

DangKy::DangKy() {

}

DangKy::~DangKy(){

}

void DangKy::dangky(SinhVien& sv, KhoaHoc& kh) {
	//check dieu kien co duoc dang ky hay khong
	if (sv.TKB.lichbieu.size() == 5) {
		cout << "Sinh vien da dang ky 5 mon hoc roi!!" << endl;
	}
	else if (kh.bangphancong.bangphancong.size() == 40) {
		cout << "Mon hoc da du 40 sinh vien!!!" << endl;
	}
	else {
		for (int i = 0; i < sv.TKB.lichbieu.size(); i++) {
			if (strcmp(sv.TKB.lichbieu[i].TenMH, kh.TenKH) == 0) {
				cout << "Ban da dang ky mon nay roi." << endl;
				return;
			}
		}
		Monhoc tempMH;
		tempMH.TenMH = new char[100]();
		strcpy_s(tempMH.TenMH,100, kh.TenKH);
		sv.TKB.lichbieu.push_back(tempMH);

		TenSinhVien tempTenSV;
		tempTenSV.TenSV = new char[100]();
		strcpy_s(tempTenSV.TenSV,100, sv.TenSV);
		kh.bangphancong.bangphancong.push_back(tempTenSV);

		cout <<endl<< "==============Thoi khoa bieu SV=============" << endl;
		sv.print();
		cout << "Cac mon hoc sinh vien nay da dang ky:" << endl;
		sv.TKB.print();
		cout << "=============================================" << endl;

		cout << endl << "=======Danh sach sinh vien tham gia mon hoc=====" << endl;
		kh.print();
		cout << "Danh sach sinh vien dang ky khoa hoc nay:" << endl;
		kh.bangphancong.print();
		cout << "=============================================" << endl;
	}
}

void DangKy::dangky(SinhVien& sv, DanhSachKhoaHoc& ds, int index) {
	if (index-1 < 0 || index-1 >= ds.danhsach.size()) {
		cout << "Dang ky sai, dang ky lai." << endl;
		return;
	}
	DangKy::dangky(sv, *ds.danhsach[index - 1]);
}

void DangKy::dangky(DanhSachSinhVien& dssv, const int &index1, DanhSachKhoaHoc& dskh,const int &index2) {
	if (index2 - 1 < 0 || index2 - 1 >= dskh.danhsach.size()) {
		cout << "Dang ky sai, dang ky lai." << endl;
		return;
	}
	if (index1 - 1 < 0 || index1 - 1 >= dssv.danhsach.size()) {
		cout << "Thong tin sinh vien sai, dang ky lai." << endl;
		return;
	}
	DangKy::dangky(*dssv.danhsach[index1 - 1], *dskh.danhsach[index2 - 1]);
}