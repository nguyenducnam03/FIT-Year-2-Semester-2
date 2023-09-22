#include "BieuThuc.h"
#include"DonThuc.h"
#include "BieuThucCong.h"
#include "BieuThucTru.h"
#include "BieuThucNhan.h"

int main()
{   
    int x = 10;

    //ve1
    BieuThuc* bt1 = new DonThuc(3, 1);
    BieuThuc* bt2 = new DonThuc(5,0);
    BieuThuc* bt3 = new DonThuc(4, 1);
    BieuThuc* bt4 = new DonThuc(6, 0);
    BieuThuc* bt5 = new DonThuc(7, 1);
    BieuThuc* bt6 = new DonThuc(2, 0);
    BieuThuc* bt7 = new DonThuc(2, 2);
    BieuThuc* bt8 = new DonThuc(3, 1);
    BieuThuc* bt9 = new DonThuc(1, 0);

    BieuThuc* btcong1 = new BieuThucCong();
    btcong1->themBieuThuc(bt1);
    btcong1->themBieuThuc(bt2);

    BieuThuc* bttru1 = new BieuThucTru();
    bttru1->themBieuThuc(bt3);
    bttru1->themBieuThuc(bt4);

    BieuThuc* btnhan1 = new BieuThucNhan();
    btnhan1->themBieuThuc(btcong1);
    btnhan1->themBieuThuc(bttru1);

    BieuThuc* btcong2 = new BieuThucCong();
    btcong2->themBieuThuc(bt5);
    btcong2->themBieuThuc(bt6);

    cout << btnhan1->tinhF(x) << endl;
    cout << btcong2->tinhF(x) << endl;

    BieuThuc* bttru2 = new BieuThucTru();
    bttru2->themBieuThuc(btnhan1);
    bttru2->themBieuThuc(btcong2);
    //Ve2
    BieuThuc* btcong3 = new BieuThucCong();
    btcong3->themBieuThuc(bt7);
    btcong3->themBieuThuc(bt8);
    btcong3->themBieuThuc(bt9);

    cout << bttru2->tinhF(x) << endl;
    cout << btcong3->tinhF(x) << endl;


    BieuThuc* btFinal = new BieuThucNhan();
    btFinal->themBieuThuc(bttru2);
    btFinal->themBieuThuc(btcong3);

    cout << btFinal->tinhF(x) << endl;


    cout << "Hello World!\n";
    return 0;
}