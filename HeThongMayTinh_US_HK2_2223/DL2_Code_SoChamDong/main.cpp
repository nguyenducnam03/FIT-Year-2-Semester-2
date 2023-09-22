#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Cau1
//chuyen doi tu so thuc sang ma nhi phan
//input: dia chi so float nay
//output: in ra ma nhi phan tuong ung cua so float nay
/*HD: May luu duoi ma nhi phan san, ta chi can in ra, nhung float * khong duoc
ta muon *long de bieu dien, roi in ra ma nhi phan nay
*/
void dumpFloat(float *p){
    char sign;
    if (*p>=0){
        sign = '0';
    }
    else {
        sign = '1';
    }

    *p = abs(*p);

    long *pl = (long *)&*p;
    string re = "";
    while (*pl>0){
        if (*pl & 1){
            re = "1" + re;
        }
        else {
            re = "0" + re;
        }
        *pl = *pl >> 1;
    }

    while (re.length()<31){
        re = "0" + re;
    }

    string exponent = re.substr(0, 8);
    string significant = re.substr(8, re.length() - 8);

    cout << "sign   exponent    significand: " << endl;
    cout << sign << "   " << exponent << "  " << significant << endl;

    cout << endl;
}

//Cau2
//Tu ma nhi phan la dia chi float, chuyen ve gia tri float
//Input: dia chi so float p, ma nhi phan s
//Output: Gia tri float tu s luu vao bien p
/*HD:Ta cung muon long* de luu ma nhi phan, sau do chuyen thanh gia tri
float dua vao dia chi nhi phan nay 
Dung XOR de dua tung bit 1 vao bien long temp
*/
void forceFloat(float *p, string &s){
    long temp = 0;
    for (int i = 0; i < s.length();i++){
        if (s[i]=='1'){
            temp = temp ^ (1 << (31 - i));
        }
    }
    *p = *(float *)&temp;
}

//Cau3 Khao sat cac cac hoi theo yeu cau
void Cau3(){
    cout << endl;
    cout << "So 1.3E20 bieu dien thanh ma nhi phan: " << endl;
    float temp1 = 1.3e20;
    dumpFloat(&temp1);
    cout << endl;

    cout << "So duong nho nhat lon hon 0: " << endl;
    string temp2 = "000000001";
    forceFloat(&temp1, temp2);
    cout << temp1 << endl;
    cout << "Ma nhi phan so duong do: " << endl;
    dumpFloat(&temp1);
    cout << endl;

    //Truong hop tao ra so vo cung
    //Khi exponent toan la 1 va significand toan la 0
    //Khi gia tri > max float ~~ 3.4E38
    temp2 = "011111111";
    forceFloat(&temp1, temp2);
    cout << temp2 << " : " << temp1 << endl;
    dumpFloat(&temp1);
    cout << endl;

    //Tao ra so bao loi NaN
    //Khi ma nhi phan exponent toan 1, significant khac 0
    //Gia tri 0/0,.. (khong test bang cach nhap vao duoc, phai su dung bien phu)
    temp2 = "0111111110001";
    forceFloat(&temp1, temp2);
    cout << temp2 << " : " << temp1 << endl;
    dumpFloat(&temp1);
    cout << endl;

    float t1, t2;
    cout << "Mot so tru vo cung: " << endl;
    t1 = 15.2;
    temp2 = "011111111";
    forceFloat(&t2, temp2);
    cout << t1 << " " << t2 << endl;
    cout << "Ket qua phep tru: " << t1 - t2 << endl;
    cout << endl;

    cout << "Vo cung tru vo cung: " << endl;
    temp2 = "011111111";
    forceFloat(&t1, temp2);
    forceFloat(&t2, temp2);
    cout << t1 << " " << t2 << endl;
    cout << "Ket qua phep tru: " << t1 - t2 << endl;
    cout << endl;

    cout << "X/0: " << endl;
    t1 = 15.2;
    temp2 = "0";
    forceFloat(&t2, temp2);
    cout << t1 << " " << t2 << endl;
    cout << "Ket qua phep chia: " << t1 / t2 << endl;
    cout << endl;

    cout << "0/0: " << endl;
    temp2 = "0";
    forceFloat(&t1, temp2);
    forceFloat(&t2, temp2);
    cout << t1 << " " << t2 << endl;
    cout << "Ket qua phep chia: " << t1 / t2 << endl;
    cout << endl;

    cout << "Can bac hai so am: " << endl;
    t1 = -15.2;
    cout << t1 << endl;
    cout << "Ket qua phep chia: " << sqrt(t1) << endl;
    cout << endl;
}

void XuliCau4(){
    while(true){
        float f1, f2, f3;
        int t1;
        cout << "Chon y trong cau 4: " << endl;
        int selection;
        cin >> selection;
        while (selection < 0 || selection>4) {
            cout << "Nhap sai, vui long nhap lai: ";
            cin >> selection;
        }
        switch (selection) {
        case 1:
            cout << "Y 1. Chuyen doi float -> int -> float.  : " << endl;
            cout << "Nhap so float :";
            cin >> f1;
            f1 = (float)(int)f1;
            cout << "Sau khi chuyen doi: " << f1 << endl
                 << endl;
            break;
        case 2:
            cout << "Y 2. Chuyen doi int -> float -> int. " << endl;
            cout << "Nhap so int: ";
            cin >> t1;
            t1 = (int)(float)t1;
            cout << "Sau khi chuyen doi: " << t1 << endl
                 << endl;
            break;
        case 3:
            cout << "Y 3. Tinh ket hop phep cong float "<< endl;
            cout << "Nhap 3 so float: " << endl;
            cin >> f1 >> f2 >> f3;
            cout << "(x+y)+z = " << (f1 + f2) + f3 << endl;
            cout << "x+(y+z) = " << f1 + (f2 + f3) << endl;
            cout << endl;
            break;
        case 4:
            cout << "Y 4 -> 9. Cac yeu cau chuyen doi rieng. "<< endl;
            cout << "Nhap so float: " << endl;
            cin >> f1;
            t1 = (int)(3.14159 * f1);
            f1 = f1 + (float)t1;
            if (t1==(int)((float) t1)){
                cout << "True 1" << endl;
            }
            else{
                cout << "False 1" << endl;
            }

            if (t1==(int)((double) t1)){
                cout << "True 2" << endl;
            }
            else{
                cout<<"False 2" << endl;
            }

            if (f1==(float)((int) f1)){
                cout << "True 3" << endl;
            }
            else{
                cout << "False 3" << endl;
            }

            if (f1==(double)((int) f1)){
                cout << "True 4" << endl;
            }
            else{
                cout << "False 4" << endl;
            }
            break;
        case 0:
            cout << "Thoat!!!\n";
            return;
            break;
        }
    }

}

//Cau4 Khao sat cac truong hop theo yeu cau
void Cau4(){
    cout << endl
         << "   Menu Cau4. Moi ban chon :" << endl;
    cout << "   Y 1: Chuyen doi float -> int -> float.    Phim 1" << endl
         << "   Y 2: Chuyen doi int -> float -> int.      Phim 2" << endl
         << "   Y 3: Tinh ket hop phep cong float.        Phim 3" << endl
         << "   Y 4 -> 9: Cac yeu cau chuyen doi rieng.   Phim 4" << endl
         << "   Thoat Cau 4!!!!                           Phim 0" << endl
         << "   ===========================================" << endl;

    XuliCau4();
}



void Xulichinh(){
    while (true){
        float f1;
        string s1;
        cout << "Chon cau trong bai: " << endl;
        int selection;
        cin >> selection;
        while (selection < 0 || selection>4) {
            cout << "Nhap sai, vui long nhap lai: ";
            cin >> selection;
        }
        switch (selection) {
        case 1:
            cout << "1.Tu float sang ma nhi phan: " << endl;
            cout << "Nhap so thuc can chuyen (luu y chi co the nhap dung pham vi nho hon 3.e38, chu khong dung cin voi so lon hon, so lon hon chi co the gan truc tiep): " << endl;
            cin >> f1;
            // cout << "this: " << endl;
            dumpFloat(&f1);
            break;
        case 2:
            cout << "2.Tu ma nhi phan thanh gia tri: " << endl;
            cout << "Nhap ma nhi phan: " << endl;
            cin >> s1;
            forceFloat(&f1, s1);
            cout << f1 << endl
                << endl;
            break;
        case 3:
            cout << "3.Khao sat cac cau hoi: "<< endl;
            Cau3();
            break;
        case 4:
            cout << "4.Khao sat cac truong hop: "<< endl;
            Cau4();
            break;
        case 0:
            cout << "Thoat!!!\n";
            return;
            break;
        }
    }
}

void Menu(){
    cout << endl
         << "Menu chinh. Moi ban chon cau:" << endl;
    cout << "Cau 1: Tu float sang ma nhi phan.    Phim 1" << endl
         << "Cau 2: Tu ma nhi phan thanh gia tri. Phim 2" << endl
         << "Cau 3: Khao sat cac cau hoi.         Phim 3" << endl
         << "Cau 4: Khao sat cac truong hop.      Phim 4" << endl
         << "Thoat!!!!                            Phim 0" << endl
         << "===========================================" << endl;

    Xulichinh();
}

int main(){
    Menu();

    cout << endl
         << "Hello world" << endl;
    return 0;
}