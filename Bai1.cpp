#include <string>
#include <iostream>
#include <stdio.h>
#include <conio.h>

#define _CRT_SECURE_NO_WARNINGS

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
    MuiTiem* muiTiem;
};

void xuatVaccine(MuiTiem* k) {
    cout << k->loai << ": ";
    cout << k->ngayTiem.ngay << "/" << k->ngayTiem.thang;
    cout << "/" << k->ngayTiem.nam << endl;
}

void xuatCaNhan(Covid19* k) {
    cout << k->cccd << endl;
    cout << k->ten << endl;
    cout << k->ngaySinh.ngay << "/" << k->ngaySinh.thang;
    cout << "/" << k->ngaySinh.nam << endl;
    for (int i = 0; i < k->soMui; ++i) {
        xuatVaccine((k->muiTiem) + i);
    }
}

void xuatDanhSach(Covid19* danhSach, int n) {
    for (int i = 0; i < n; i++) {
        cout << "-----STT. " << i + 1 << "-----\n";
        xuatCaNhan(danhSach + i);
    }
}

void nhapMuiTiem(MuiTiem* k) {
    cout << "Nhap so thu tu mui tiem:";
    cin >> k->stt;
    cout << "Nhap ten vaccine:";
    cin.ignore();
    getline(cin, k->loai);
    cout << "Nhap ngay tiem (vd: 11 11 2021):";
    cin >> k->ngayTiem.ngay >> k->ngayTiem.thang >> k->ngayTiem.nam;
    cout << "Nhap dia chi duoc tiem: ";
    cin >> k->noiTiem;
}

void nhapThongTin(Covid19* k) {
    cout << "Nhap CMND/CCCD: ";
    cin >> k->cccd;
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, k->ten);
    cout << "Nhap ngay thang nam sinh (vd: 01 02 2002): ";
    cin >> k->ngaySinh.ngay >> k->ngaySinh.thang >> k->ngaySinh.nam;
    cout << "Nhap so mui da duoc tiem: ";
    cin >> k->soMui;
    k->muiTiem = new MuiTiem[k->soMui];
    for (int i = 0; i < k->soMui; i++) {
        nhapMuiTiem((k->muiTiem) + i);
    }
}

void nhapDanhSach(Covid19*& danhSach, int n) {
    danhSach = new Covid19[n + 20];
    for (int i = 0; i < n; i++) {
        nhapThongTin(danhSach + i);
    }
}

//void themPhanTu(Covid19*& danhSach, int n) {
//    nhapThongTin(danhSach + n);
//    n++;
//}

void suaThongTin(Covid19*& k, string id, int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (k[i].cccd == id) {
            found = 1;
            cout << "Sua thong tin cua nguoi co CMND/CCCD " << id << "." << endl;
            nhapThongTin(k + i);
            break;
        }
    }
    if (found == 0) {
        cout << "Nguoi co CMND/CCCD " << id << " khong ton tai." << endl;
    }
}

int xoaTheoCCCD(Covid19* k, string id, int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (k[i].cccd == id) {
            found = 1;
            for (int j = i; j < n; j++) {
                k[j] = k[j + 1];
            }
            cout << "Xoa thanh cong." << endl;
            break;
        }
    }
    if (found == 0) {
        cout << "Nguoi co CMND/CCCD " << id << " khong ton tai." << endl;
        return 0;
    }
    else
        return 1;
}

void sapXepTheoCMND(Covid19* k, int n) {
    Covid19 tmp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (k[i].cccd > k[j].cccd) {
                tmp = k[i];
                k[i] = k[j];
                k[j] = tmp;
            }
        }
    }
}

void xacDinhChuaTiemKMui(Covid19* k, int K, int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (k[i].soMui < K) {
            found++;
            xuatCaNhan(k + i);
        }
    }
    if (found == 0) {
        cout << "Khong co nguoi nao tiem duoi " << K << " mui." << endl;
    }
}

int main() {
    int n, key, soluongSV = 0;
    //freopen("input1.txt", "r", stdin);

    Covid19* danhSach = new Covid19[50];

    cout << "CHUONG TRINH QUAN LY DANH SACH TIEM NGUA COVID-19\n";
    cout << "*************************MENU**************************\n";
    cout << "**  1. Nhap danh sach.                               **\n";
    cout << "**  2. Them 1 phan tu.                               **\n";
    cout << "**  3. Sua thong tin 1 phan tu.                      **\n";
    cout << "**  4. Xoa 1 phan tu.                                **\n";
    cout << "**  5. Sap xep danh sach theo so CMND/CCCD.          **\n";
    cout << "**  6. Xuat danh sach.                               **\n";
    cout << "**  7. Xac dinh nhung nguoi chua tiem du K mui.      **\n";
    cout << "**  0. Thoat.                                        **\n";
    cout << "*******************************************************\n";
    do {
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch (key) {
        case 1:
            cout << "\n1. Nhap so phan tu can them vao danh sach: ";
            cin >> n;
            nhapDanhSach(danhSach, n);
            cout << "\nThem thanh cong!" << endl;
            soluongSV = n;
            break;
            /* case 2:
                 cout << "\n7. Dien thong tin phan tu duoc them vao.\n";
                 themPhanTu(danhSach, soluongSV);
                 cout << "Them thanh cong!" << endl;
                 break;*/
        case 3:
            if (soluongSV > 0) {
                string id;
                cout << "\n3. Nhap CMND/CCCD cua nguoi can duoc chinh sua: ";
                cin >> id;
                suaThongTin(danhSach, id, soluongSV);
            }
            else {
                cout << "\nDanh sach trong!";
            }
            break;
        case 4:
            if (soluongSV > 0) {
                string id;
                cout << "\n4. Nhap CMND/CCCD cua nguoi can bi xoa: ";
                cin >> id;
                if (xoaTheoCCCD(danhSach, id, soluongSV) == 1) {
                    cout << "\nNguoi co CMND/CCCD = " << id << " da bi xoa." << endl;
                    soluongSV--;
                }
            }
            else {
                cout << "\nDanh sach trong!";
            }
            break;
        case 5:
            if (soluongSV > 0) {
                cout << "\n5. Sap xep danh sach theo CMND/CCCD.";
                sapXepTheoCMND(danhSach, soluongSV);
                xuatDanhSach(danhSach, soluongSV);
            }
            else {
                cout << "\nDanh sach trong!";
            }
            break;
        case 6:
            if (soluongSV > 0) {
                cout << "\n6. Xuat danh sach.\n";
                xuatDanhSach(danhSach, n);
            }
            else {
                cout << "\nDanh sach trong!";
            }
            break;
        case 7:
            if (soluongSV > 0) {
                int K;
                cout << "\n7. Nhap so mui yeu cau: ";
                cin >> K;
                cout << "Nhung nguoi chua tiem du " << K << " mui la:\n";
                xacDinhChuaTiemKMui(danhSach, K, soluongSV);
            }
            else {
                cout << "Danh sach trong!";
            }
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