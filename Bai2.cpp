#include <string>
#include <iostream>

using namespace std;

struct Ngay {
	int ngay, thang, nam;
};


struct F0 {
	string maSo;
	string ten;
};

struct Covid19 {
	Ngay ngayGhiNhan;
	int soF0;
	F0 * danhSachF0;
};

void nhapF0(F0 * k) {
	cin >> k->maSo;
	cin.ignore();
	getline(cin, k->ten);	
}

void nhapThongTin(Covid19 * k) {	
	cin >> k->ngayGhiNhan.ngay >> k->ngayGhiNhan.thang >> k->ngayGhiNhan.nam;	
	cin >> k->soF0;
	k->danhSachF0 = new F0[k->soF0];
	for (int i = 0; i < k->soF0; i++) {
		nhapF0((k->danhSachF0) + i);
	}
}

void nhapDanhSach(Covid19 *& danhSach, int n) {
	danhSach = new Covid19[n + 20];
	for (int i = 0; i < n; i++) {
		nhapThongTin(danhSach + i);
	}	
}

void xuatCaNhan(F0 * k) {
	cout << k->maSo << endl;
	cout << k->ten << endl;
}

void xuatTungNgay(Covid19 * k) {
	cout << k->ngayGhiNhan.ngay << "/" << k->ngayGhiNhan.thang;	
	cout << "/" << k->ngayGhiNhan.nam << endl;
	for (int i = 0; i < k->soF0; ++i) {
		xuatCaNhan((k->danhSachF0) + i);
	}
}

void xuatDanhSach(Covid19 * danhSach, int n) {
	for (int i = 0; i < n; i++) {
		cout << "-----STT. " << i << "-----\n";
		xuatTungNgay(danhSach + i);
	}
	
}

int main () {
	int n;
	freopen("input2.txt", "r", stdin);
	Covid19 * danhSach;
	cin >> n;
	nhapDanhSach(danhSach, n);
	xuatDanhSach(danhSach, n);
	cout << "OK";
	delete[] danhSach;
}