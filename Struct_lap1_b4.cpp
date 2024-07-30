#include<iostream>
#include<string>
using namespace std;

#define max 50

struct SinhVien
{
	string maSV;
	string hoten;
	string diachi;
	double diemtoan;
	double diemvan;
	double diemnn;
};

struct Lop
{
	SinhVien dsl[max];
	int n;
};

void Nhap1sv(SinhVien& sv)
{
	cout << "Nhap ma sinh vien: ";
	getline(cin, sv.maSV);
	cout << "Nhap ten sinh vien: ";
	getline(cin, sv.hoten);
	cout << "Nhap dia chi: ";
	getline(cin, sv.diachi);
	cout << "Nhap diem toan: ";
	cin >> sv.diemtoan;
	cout << "Nhap diem van: ";
	cin >> sv.diemvan;
	cout << "Nhap diem mgoai ngu: ";
	cin >> sv.diemnn;
}

void Xuat1sv(SinhVien sv)
{
	cout << "=========================\n";
	cout << "Ma sinh vien: " << sv.maSV << endl;
	cout << "Ten sinh vien: " << sv.hoten << endl;
	cout << "Dia chi: " << sv.diachi << endl;
	cout << "Diem toan: " << sv.diemtoan << endl;
	cout << "Diem van: " << sv.diemvan << endl;
	cout << "Diem mgoai ngu: " << sv.diemnn << endl;
}

void Nhapdsl(Lop& lop)
{
	cout << "Nhap so luong sinh vien: ";
	cin >> lop.n;
	while (lop.n < 1 || lop.n>45)
	{
		cout << "Vuot qua so luong sinh vien cho phep!\nVui long nhap lai: ";
		cin >> lop.n;
	}
	for (int i = 0; i < lop.n; i++)
	{
		cin.ignore();
		Nhap1sv(lop.dsl[i]);
		cout << endl;
	}
}

void Xuatdsl(Lop lop)
{
	for (int i = 0; i < lop.n; i++)
	{
		Xuat1sv(lop.dsl[i]);
	}
}

void Xuatyeucau(Lop lop)
{
	int i = 0;
	cout << "Nhap so thu tu cua sinh vien: ";
	cin >> i;
	cout << "Thong tin sinh vien thu " << i << ": \n";
	Xuat1sv(lop.dsl[i - 1]);
}

double Diemtrungbinh(SinhVien sv)
{
	return ((sv.diemtoan + sv.diemvan) * 2 + sv.diemnn) / 5;
}

void Xephangsv(SinhVien sv)
{
	double dtb = Diemtrungbinh(sv);
	cout << "Xep loai: ";
	if (dtb >= 8)
	{
		cout << "Gioi";
	}
	else if (dtb < 8 && dtb >= 6.5)
	{
		cout << "Kha";
	}
	else if (dtb < 6.5 && dtb >= 5)
	{
		cout << "Trung binh";
	}
	else
	{
		cout << "Duoi Trung binh";
	}
}

int main() {
	SinhVien sv;
	Lop lop;
	int op = 0;
	bool check = true;

	while (check)
	{
		cout << "                 MENU\n";
		cout << "1. Nhap thong tin sinh vien cua 1 lop hoc\n";
		cout << "2. Xuat thong tin sinh vien theo yeu cau nguoi dung\n";
		cout << "3. Xuat thong tin sinh vien sau khi tinh diem trung binh va xep loai cua sinh vien\n";
		cout << "      Nhan 1 phim bat ky de ket thuc chuong trinh\n\n";
		cout << "===> LUA CHON: ";
		cin >> op;

		switch (op)
		{
		case 1:
		{
			Nhapdsl(lop);
			Xuatdsl(lop);
			break;
		}
		case 2:
		{
			Xuatyeucau(lop);
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "            DSSV SAU KHI THAY DOI\n";
			for (int i = 0; i < lop.n; i++)
			{
				Xuat1sv(lop.dsl[i]);
				cout << "Diem TB: " << Diemtrungbinh(lop.dsl[i]) << endl;
				Xephangsv(lop.dsl[i]);
				cout << endl;
			}
			break;
		}
		default: 
		{
			check = false;
			break;
		}
		}
	}

	system("pause");
	return 0;
}