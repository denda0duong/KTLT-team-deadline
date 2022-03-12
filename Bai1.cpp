#include <string>
#include <iostream>

using namespace std;

struct Ngay {
	int ngay, thang, nam;
};

struct MuiTiem {
	int stt;
	string loai;
	Ngay ngayTiem;
	int noiTiem;
};

struct Covid19 {
	string cccd;
	string ten;
	Ngay ngaySinh;
	int soMui;
	MuiTiem * muiTiem;
};

void nhapMuiTiem(MuiTiem * k) {
	cin >> k->stt;
	cin.ignore();
	getline(cin, k->loai);	
	cin >> k->ngayTiem.ngay >> k->ngayTiem.thang >> k->ngayTiem.nam;
	cin >> k->noiTiem;
}

void nhapThongTin(Covid19 * k) {
	cin >> k->cccd;
	cin.ignore();
	getline(cin, k->ten);	
	cin >> k->ngaySinh.ngay >> k->ngaySinh.thang >> k->ngaySinh.nam;
	
	cin >> k->soMui;
	k->muiTiem = new MuiTiem[k->soMui];
	for (int i = 0; i < k->soMui; i++) {
		nhapMuiTiem((k->muiTiem) + i);
	}
}

void nhapDanhSach(Covid19 *& danhSach, int n) {
	danhSach = new Covid19[n + 20];
	for (int i = 0; i < n; i++) {
		nhapThongTin(danhSach + i);
	}	
}

void xuatVaccine(MuiTiem * k) {
	cout << k->loai << ": ";
	cout << k->ngayTiem.ngay << "/" << k->ngayTiem.thang;	
	cout << "/" << k->ngayTiem.nam << endl;
}

void xuatCaNhan(Covid19 * k) {
	cout << k->cccd << endl;
	cout << k->ten << endl;
	cout << k->ngaySinh.ngay << "/" << k->ngaySinh.thang;	
	cout << "/" << k->ngaySinh.nam << endl;
	for (int i = 0; i < k->soMui; ++i) {
		xuatVaccine((k->muiTiem) + i);
	}
}

void xuatDanhSach(Covid19 * danhSach, int n) {
	for (int i = 0; i < n; i++) {
		cout << "-----STT. " << i << "-----\n";
		xuatCaNhan(danhSach + i);
	}
	
}

int main () {
	int n;
	freopen("input1.txt", "r", stdin);
	Covid19 * danhSach;
	cin >> n;
	nhapDanhSach(danhSach, n);
	xuatDanhSach(danhSach, n);

	delete[] danhSach;
}