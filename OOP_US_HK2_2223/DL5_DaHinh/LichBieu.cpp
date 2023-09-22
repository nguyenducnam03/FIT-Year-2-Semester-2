#include "LichBieu.h"

LichBieu::LichBieu() {

}

LichBieu::~LichBieu(){
	int size = lichbieu.size();
	for (int i = 0; i < size; i++) {
		Monhoc temp = lichbieu[lichbieu.size() - 1];
		lichbieu.pop_back();
		delete[] temp.TenMH;
	}
}

void LichBieu::print() {
	for (int i = 0; i < lichbieu.size(); i++) {
		cout << lichbieu[i].TenMH << endl;
	}
}