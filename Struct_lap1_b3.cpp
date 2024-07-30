#include<iostream>
#include<string>
using namespace std;

struct NhanVien
{
	string maNV;
	string tenNv;
	int namvaolam;
	int namsinh;
};

void Nhap1NV(NhanVien& nv)
{
	cout << "Nhap ma nhan vien: ";
	getline(cin, nv.maNV);
	cout << "Nhap ten nhan vien: ";
	getline(cin, nv.tenNv);
	cout << "Nhap nam vao lam: ";
	cin >> nv.namvaolam;
	cout << "Nhap nam sinh: ";
	cin >> nv.namsinh;
}

void Xuat1NV(NhanVien nv)
{
	cout << "Ma nhan vien: " << nv.maNV << endl;
	cout << "Ten nhan vien: " << nv.tenNv << endl;
	cout << "Nam vao lam: " << nv.namvaolam << endl;
	cout << "Nam sinh: " << nv.namsinh << endl;
}

int Tuoi(NhanVien nv, int namhientai = 2024)
{
	return namhientai - nv.namsinh;
}

int Thamnien(NhanVien nv, int namhientai = 2024)
{
	return namhientai - nv.namvaolam;
}

int main()
{
	NhanVien nv;
	Nhap1NV(nv);
	Xuat1NV(nv);

	cout << "Tuoi cua nhan vien: " << Tuoi(nv) << endl;
	cout << "Tham nien cua nhan vien: " << Thamnien(nv) << endl;

	system("pause");
	return 0;
}