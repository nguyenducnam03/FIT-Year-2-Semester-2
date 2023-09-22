#include "Header.h"
#include "DanhSachKhoaHoc.h"
#include "KhoaHoc.h"
#include "DanhSachSinhVien.h"
#include "SinhVien.h"
#include "DangKy.h"
#include <vector>

int main()
{
    //Cau1: Doc danh sach khoa hoc tu file inputKhoahoc.txt --> listKhoaHoc
    DanhSachKhoaHoc listKhoaHoc;
    string inputKH = "inputKhoaHoc.txt";
    listKhoaHoc.inputDanhSach(inputKH);
    //Ghi danh sach khoa hoc vao file outputKhoaHoc.txt
    string output1 = "outputKhoaHoc.txt";
    listKhoaHoc.outputDanhSach(output1);

    //Doc danh sach sinh vien tu file inputSinhVien.txt -->listSinhVien
    DanhSachSinhVien listSinhVien;
    string inputSV = "inputSinhVien.txt";
    listSinhVien.inputDanhSach(inputSV);
    //Ghi danh sach khoa hoc vao file outputSinhVien.txt
    string output2 = "outputSinhVien.txt";
    listSinhVien.outputDanhSach(output2); 

    //File record dang ky cua cac sinh vien
    //Format STT SV --> Cac mon hoc (STT) --> 0 (ki tu ket thuc luot dk sinh vien nay)
    // Sinh vien dang ky khoa hoc
    fstream myFile;
    string fileDK = "danhsachdangky.txt";
    myFile.open(fileDK, ios::in);
    if (myFile.is_open()) {
        int sinhvien;
        vector<int> dangky;
        int temp;
        while (!myFile.eof()) {
            myFile >> sinhvien;
            myFile >> temp;
            while (temp != 0) {
                dangky.push_back(temp);
                myFile >> temp;
            }
            for (int i = 0; i < dangky.size(); i++) {
                //In danh sach sinh vien cua mot khoa hoc
                //In thoi khoa bieu cua mot sinh vien deu se duoc hien thi khi dang ky
                DangKy::dangky(listSinhVien, sinhvien, listKhoaHoc, dangky[i]);
            }
            dangky.clear();
        }

        //Thoi khoa bieu cua toan bo sinh vien
        cout << "=======================" << endl
            << "THOI KHOA BIEU CUA TOAN BO SINH VIEN" << endl;
        listSinhVien.thoikhoabieu();


        cout << "========================" << endl
            << "SINH VIEN DANG KY KHOA HOC" << endl;
        listKhoaHoc.sinhviencuakhoahoc();

        myFile.close();
    }
    else {
        cout << "File can't open" << endl;
    }

    cout << "Hello World!\n";
    return 0;
}
