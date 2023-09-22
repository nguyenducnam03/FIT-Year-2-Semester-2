#include "DonThuc.h"

DonThuc::DonThuc(){

}

DonThuc::DonThuc(const int& a ) {
	heso = a;
	somu = 1;
}

DonThuc::DonThuc(const int& a , const int& b){
		heso = a;
		somu = b;
}

DonThuc::~DonThuc(){

}

float DonThuc::tinhF(int& x){
	return heso * pow(x, somu);
}

void DonThuc::themBieuThuc(BieuThuc* bt) {
	return;
}
