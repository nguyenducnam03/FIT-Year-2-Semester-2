#include "NhanVien.h"
#include "NhanVienSanXuat.h"
#include "NhanVienCongNhat.h"
#include "CongTy.h"


void Xuly() {
    bool checkkhoitao = false;
    string filename = "ds_nhanvien.dat";
    CongTy congty1;
    CongTy congty2;
    while (true) {
        cout << "chon cau: " << endl;
        int selection;
        cin >> selection;
        while (selection < 0 || selection>13) {
            cout << "nhap sai, vui long nhap lai: ";
            cin >> selection;
        }
        switch (selection) {
        case 1:
            checkkhoitao = true;
            cout << "phim 1. khoi tao danh sach va ghi vao file ds_nhanvien.dat." << endl;
            filename = "ds_nhanvien.dat";
            congty1.input();
            congty1.c1_ghiDSNV(filename);
            break;
        case 2:
            //if (checkkhoitao) {
                cout << "phim 2. doc danh sach nhan vien tu file ds_nhanvien.dat. " << endl;
                filename = "ds_nhanvien.dat";
                congty1.c2_docDSNV(filename);
                checkkhoitao = true;

            break;
        case 3:
            if (checkkhoitao) {
                cout << "phim 3. xuat danh sach nhan vien ra man hinh. " << endl;
                congty1.c3_xuatDSNV();
            }
            else {
                cout << "ban chua khoi tao danh sach" << endl;
            }
            break;
        case 4:
            if (checkkhoitao) {
                cout << "phim 4. in tong tien luong tat ca nhan vien. " << endl;
                cout << congty1.c4_getLuong() << endl;
            }
            else {
                cout << "ban chua khoi tao danh sach" << endl;
            }
            break;
        case 5:
            if (checkkhoitao) {
                cout << "phim 5. tim nhan vien co luong cao nhat. " << endl;
                congty1.c5_timNVLuongMax();
            }
            else {
                cout << "ban chua khoi tao danh sach" << endl;
            }
            break;
        case 6:
            if (checkkhoitao) {
                cout << "phim 6. tinh luong trung binh cong ty. " << endl;
                cout << "luong trung binh cong ty: " << congty1.c6_AVGLuong() << endl;
            }
            else {
                cout << "ban chua khoi tao danh sach" << endl;
            }
            break;
        case 7:
            if (checkkhoitao) {
                cin.ignore();
                cout << "phim 7. tim nhan vien theo manv. " << endl;
                congty1.c7_timNVtheoMa();
            }
            else {
                cout << "ban chua khoi tao danh sach" << endl;
            }
            break;
        case 8:
            if (checkkhoitao) {
                cin.ignore();
                cout << "phim 8. tim nhan vien theo tennv. " << endl;
                congty1.c8_timNVtheoTen();
            }
            else {
                cout << "ban chua khoi tao danh sach" << endl;
            }
            break;
        case 9:
            if (checkkhoitao) {
                cout << "phim 9. tim cac nhan vien sinh trong thang 5. " << endl;
                congty1.c9_timNVSinhThang5(5);
            }
            else {
                cout << "ban chua khoi tao danh sach" << endl;
            }
            break;
        case 10:
            if (checkkhoitao) {
                cout << "phim 10. them mot nhan vien va cap nhap vao file ds_nhanvien.dat. " << endl;
                filename = "ds_nhanvien.dat";
                congty1.c10_themvacapnhap(filename);
                //congty1.c1_ghidsnv(filename);
                //congty1.c3_xuatdsnv();
            }
            else {
                cout << "ban chua khoi tao danh sach" << endl;
            }
            break;
        case 11:
            if (checkkhoitao) {
                cout << "phim 11. xoa mot nhan vien va cap nhap vao file ds_nhanvien.dat. " << endl;
                filename = "ds_nhanvien.dat";
                congty1.c11_xoavacapnhap(filename);
                //congty1.c3_xuatdsnv();
                //congty1.c1_ghidsnv(filename);
            }
            else {
                cout << "ban chua khoi tao danh sach" << endl;
            }
            break;
        case 12:
            if (checkkhoitao) {
                filename = "emp_loweravgsalary.dat";
                congty1.c12_ghiNVLuongThapHonTB(filename);
            }
            else {
                cout << "ban chua khoi tao danh sach" << endl;
            }
            break;
        case 0:
            cout << "thoat!!!\n";
            return;
            break;
        }
        cout << "=====chuong trinh quan ly nhan vien=====" << endl;
        cout << "bam phim tuong ung de chon cac yeu cau: " << endl;
        cout << "phim 1. khoi tao va ghi danh sach nhan vien vao file ds_nhanvien.dat." << endl
            << "phim 2. doc danh sach nhan vien tu file ds_nhanvien.dat. " << endl
            << "phim 3. xuat danh sach nhan vien ra man hinh. " << endl
            << "phim 4. in tong tien luong tat ca nhan vien. " << endl
            << "phim 5. tim nhan vien co luong cao nhat. " << endl
            << "phim 6. tinh luong trung binh cong ty. " << endl
            << "phim 7. tim nhan vien theo manv. " << endl
            << "phim 8. tim nhan vien theo tennv. " << endl
            << "phim 9. tim cac nhan vien sinh trong thang 5. " << endl
            << "phim 10. them mot nhan vien va cap nhap vao file ds_nhanvien.dat. " << endl
            << "phim 11. xoa mot nhan vien va cap nhap vao file ds_nhanvien.dat. " << endl
            << "phim 12. ghi tat ca nhan vien co luong nho hon trung binh vao file emp_loweravgsalary.dat. " << endl
            << "phim 0. exit. " << endl
            << endl;
    }

}

void Menu() {
    cout << "=====Chuong trinh quan ly nhan vien=====" << endl;
    cout << "bam phim tuong ung de chon cac yeu cau: " << endl;
    cout << "phim 1. khoi tao va ghi danh sach nhan vien vao file ds_nhanvien.dat." << endl
        << "phim 2. doc danh sach nhan vien tu file ds_nhanvien.dat. " << endl
        << "phim 3. xuat danh sach nhan vien ra man hinh. " << endl
        << "phim 4. in tong tien luong tat ca nhan vien. " << endl
        << "phim 5. tim nhan vien co luong cao nhat. " << endl
        << "phim 6. tinh luong trung binh cong ty. " << endl
        << "phim 7. tim nhan vien theo manv. " << endl
        << "phim 8. tim nhan vien theo tennv. " << endl
        << "phim 9. tim cac nhan vien sinh trong thang 5. " << endl
        << "phim 10. them mot nhan vien va cap nhap vao file ds_nhanvien.dat. " << endl
        << "phim 11. xoa mot nhan vien va cap nhap vao file ds_nhanvien.dat. " << endl
        << "phim 12. ghi tat ca nhan vien co luong nho hon trung binh vao file emp_loweravgsalary.dat. " << endl
        << "phim 0. exit. " << endl
        << endl;

    Xuly();
}


int main()
{
    Menu();

    std::cout << "hello world!\n";
    return 0;
}


