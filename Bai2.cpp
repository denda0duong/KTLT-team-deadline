#include <string>
#include <iostream>
#include <stdio.h>
#include <conio.h>

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
	cout << "Nhap ma so cua F0: ";
	cin >> k->maSo;
	cout << "Nhap ho ten F0: ";
	cin.ignore();
	getline(cin, k->ten);
}

void nhapThongTin(Covid19 * k) {
	cout << "Nhap ngay ghi nhan ca nhiem (vd: 01 02 2002): ";
	cin >> k->ngayGhiNhan.ngay >> k->ngayGhiNhan.thang >> k->ngayGhiNhan.nam;
	cout << "Nhap so F0: ";
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
	cout << "F0 so: ";
	cout << k->maSo << endl;
	cout << "Ho ten F0: ";
	cout << k->ten << endl;
}

void xuatTungNgay(Covid19 * k) {
	cout << "\nNgay ghi nhan: ";
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

void sapXepF0GiamDan(Covid19* k, int n) {
	Covid19 tmp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (k[i].soF0 < k[j].soF0) {
				tmp = k[i];
				k[i] = k[j];
				k[j] = tmp;
			}
		}
	}
}

void themPhanTu(Covid19*& danhSach, int n) {
	int k;
	Covid19* ak = new Covid19[1];

	cout << "Nhap vi tri can them: ";
	cin >> k;
	k--;
	cout << "Dien thong tin cua nguoi duoc them." << endl;
	nhapThongTin(ak + 0);

	//copy tu dau den danhSach[k-1]
	n++;
	Covid19* danhSach02 = new Covid19[n + 20];
	for (int i = 0; i < k; i++) {
		danhSach02[i] = danhSach[i];
	}
	danhSach02[k] = ak[0];
	for (int i = k + 1; i < n + 1; i++) {
		danhSach02[i] = danhSach[i - 1];
	}
	//cap phat dong lai
	delete[] danhSach;
	danhSach = new Covid19[n + 20];
	for (int i = 0; i < n; i++) {
		danhSach[i] = danhSach02[i];
	}
}

int main () {
	int n, key, soluongSV = 0;
	//freopen("input2.txt", "r", stdin);
	Covid19 * danhSach;

	cout << "CHUONG TRINH QUAN LY DANH SACH TIEM NGUA COVID-19\n";
	cout << "******************************MENU********************************\n";
	cout << "1. Tao mang dong va nhap danh sach vao mang.\n";
	cout << "2. Sap xep danh sach theo thu tu so ca F0 (giam dan).\n";
	cout << "3. Them 1 phan tu vao danh sach.\n";
	cout << "4. Xuat danh sach.\n";
	cout << "5. Luu danh sach vao File.\n";
	cout << "6. Nap danh sach tu File.\n";
	cout << "0. Thoat.\n";

	do {
		cout << "\nNhap tuy chon: ";
		cin >> key;
		switch (key) {
		case 1:
			cout << "\n1. Nhap so phan tu can them vao danh sach: ";
			cin >> n;
			soluongSV = n;
			nhapDanhSach(danhSach, n);
			cout << "\nThem thanh cong!" << endl;
			break;
		case 2:
			if (soluongSV > 0) {
				cout << "\n2. Sap xep danh sach thep thu tu so ca F0.\n";
				sapXepF0GiamDan(danhSach, soluongSV);
				xuatDanhSach(danhSach, soluongSV);
			}
			else {
				cout << "\nDanh sach trong!";
			}
			break;
		case 3:
			cout << "\n3. Them 1 phan tu vao danh sach.\n";
			if (soluongSV > 0) {

				themPhanTu(danhSach, soluongSV);
				cout << "\nThem thanh cong!" << endl;
				soluongSV++;
			}
			else {
				nhapDanhSach(danhSach, 1);
				cout << "\nThem thanh cong!" << endl;
				soluongSV++;
			}
			break;
		case 4:
			if (soluongSV > 0) {
				cout << "\n4. Xuat danh sach.\n";
				xuatDanhSach(danhSach, soluongSV);
			}
			else {
				cout << "\nDanh sach trong!";
			}
			break;
		case 5:
			cout << "\n5. Luu danh sach vao file.\n";
			break;
		case 6:
			cout << "\n6. Nap danh sach tu file.|n";
			break;
		case 0:
			cout << "\nBan da chon thoat chuong trinh!";
			break;
		default:
			cout << "\nKhong co chuc nang nay!";
			cout << "\nHay chon chuc nang trong hop menu.";
			break;
		}

	} while (key != 0);

	delete[] danhSach;

	return 0;
}