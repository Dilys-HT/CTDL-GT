#include<iostream>
using namespace std;

struct PhanSo
{
	int tuso;
	int mauso;
};

void Nhap1PS(PhanSo& ps)
{
	cout << "Nhap tu so: "; cin >> ps.tuso;
	cout << "Nhap mau so: "; cin >> ps.mauso;
}

void Xuat1PS(PhanSo ps)
{
	cout << "Phan so: " << ps.tuso << "/" << ps.mauso << endl;
}

double Tong(PhanSo ps1, PhanSo ps2)
{
	return (ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso) / (ps1.mauso * ps2.mauso * 1.0);
}

double Hieu(PhanSo ps1, PhanSo ps2)
{
	return (ps1.tuso * ps2.mauso - ps2.tuso * ps1.mauso) / (ps1.mauso * ps2.mauso * 1.0);
}

double Tich(PhanSo ps1, PhanSo ps2)
{
	return (ps1.tuso * ps2.tuso * 1.0) / (ps1.mauso * ps2.mauso*1.0);
}

double Thuong(PhanSo ps1, PhanSo ps2)
{
	return (ps1.tuso * ps2.mauso * 1.0) / (ps1.mauso * ps2.tuso * 1.0);
}

int main() {
	PhanSo ps1;
	PhanSo ps2;

	int op = 0;
	bool check = true;

	while (check)
	{
		cout << "                MENU\n";
		cout << "1. Nhap 2 phan so\n";
		cout << "2. Tong 2 phan so\n";
		cout << "3. Hieu 2 phan so\n";
		cout << "4. Tich 2 phan so\n";
		cout << "5. Thuong 2 phan so\n";
		cout << "      Nhan 1 phim bat ky de ket thuc chuong trinh\n\n";
		cout << "=====> LUA CHON CUA BAN: ";
		cin >> op;

		switch (op)
		{
		case 1:
		{
			cout << "Nhap phan so thu 1:\n";
			Nhap1PS(ps1);
			Xuat1PS(ps1);
			cout << "Nhap phan so thu 2:\n";
			Nhap1PS(ps2);
			Xuat1PS(ps2);
			if (ps1.mauso == 0 || ps2.mauso == 0)
			{
				cout << "Vo nghia! \nPhan so khong ton tai!\n";
			}
			break;
		}
		case 2:
		{
			cout << "Tong cua 2 phan so: " << Tong(ps1, ps2) << endl;
			break;
		}
		case 3:
		{
			cout << "Hieu cua 2 phan so: " << Hieu(ps1, ps2) << endl;
			break;
		}
		case 4:
		{
			cout << "Tich cua 2 phan so: " << Tich(ps1, ps2) << endl;
			break;
		}
		case 5:
		{
			cout << "Thuong cua 2 phan so: " << Thuong(ps1, ps2) << endl;
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