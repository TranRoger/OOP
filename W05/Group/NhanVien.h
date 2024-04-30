#pragma once

#include <iostream>
#include <string>

using namespace std;

// abstract class
class NhanVien {
protected:
	int _maNV;
  	string _hoTen;
  	string _phanLoai;
public:
	// constructor
  	NhanVien();
  	NhanVien(const int &);
  	NhanVien(const int &, const string &);
  	
  	// operation
  	void nhap();
  	void xuat();
  	virtual int tinhLuong() { } // abstract function
};

// concrete derived class
class NVSanXuat : public NhanVien {
private: 
	int _soSP;
public:
	// constructor
	NVSanXuat();
	NVSanXuat(const int &, const string &);	
	// operation
	void nhap();
	void xuat();
	int tinhLuong(); // implement abstract method
};

class NVCongNhat : public NhanVien {
private:
	int _soNgayLam;
public:
	// constructor
	NVCongNhat();
	NVCongNhat(const int &, const string &);
	// operation
	void nhap();
	void xuat();
	int tinhLuong(); // implement abstract method
};