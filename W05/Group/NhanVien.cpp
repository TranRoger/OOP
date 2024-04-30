#include "NhanVien.h"

// constructor
NhanVien::NhanVien(){
   cout << "NhanVien - Default cons" << endl;
   _maNV = 101;
   _hoTen = "Ho Tuan Thanh";
   _phanLoai = "NhanVien";
}


NhanVien::NhanVien(const int &maNV){
   cout << "NhanVien - 1-arg cons" << endl;
   _maNV = maNV;
   _hoTen = "Ho Tuan Thanh";
   _phanLoai = "NhanVien";
}


NhanVien::NhanVien(const int &maNV, const string &hoTen){
   cout << "NhanVien - 2-args cons" << endl;
   _maNV = maNV;
   _hoTen = hoTen;
   _phanLoai = "NhanVien";
}

NVSanXuat::NVSanXuat(){
   cout << "NVSanXuat - Default cons" << endl;
   _soSP = 0;
}

NVSanXuat::NVSanXuat(const int &maNV, const string &hoTen) : NhanVien(maNV, hoTen) {   
   cout << "NVSanXuat - 2-args cons" << endl;
}

NVCongNhat::NVCongNhat() {
    cout << "NVCongNhat - Default cons" << endl;
    _soNgayLam = 0;
}

NVCongNhat::NVCongNhat(const int &maNV, const string &hoTen) : NhanVien(maNV, hoTen) {
   cout << "NVCongNhat - 2-args cons" << endl;
}
// operation
void NhanVien::nhap(){
   do{
       cout<<"Nhap ma so: ";
       cin >> _maNV;
       if(_maNV <= 100){
           cout<<"Nhap lai!"<<endl;
       }
   }while(_maNV <= 100);
   cin.ignore(1);
   cout<<"Nhap ho ten: ";
   getline(cin, _hoTen);
   _phanLoai = "NhanVien";
}

void NVSanXuat::nhap() {
   NhanVien::nhap();
   _phanLoai = "SanXuat";
   cout << "Nhap so san pham: ";
   cin >> _soSP;
}

void NVCongNhat::nhap() {
    NhanVien::nhap();
   _phanLoai = "SanXuat";
   cout << "Nhap so ngay lam: ";
   cin >> _soNgayLam;
}


void NhanVien::xuat() {
   cout << _maNV
       << " " << _hoTen
       << " " << _phanLoai;
}

void NVSanXuat::xuat() {
   NhanVien::xuat();
   cout << " " << _soSP;
   cout << " " << tinhLuong();
}

void NVCongNhat::xuat() {
    NhanVien::xuat();
    cout << " " << _soNgayLam;
    cout << " " << tinhLuong();
}

// implementing abstract function
int NVSanXuat::tinhLuong() { 
    return _soSP * 1000;
}

int NVCongNhat::tinhLuong() {
    return _soNgayLam * 300000;
}