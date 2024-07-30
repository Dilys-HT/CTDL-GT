#include<iostream>
#include<cstring>
using namespace std;

struct NTN
{
	int ngay, thang, nam;
};

struct Sach
{
	char tensach[21];
	char tentacgia[21];
	NTN tgxuatban;
};

struct DsS
{
	Sach sach[50];
	int n;
};

bool IsNamnhuan(int nnam)
{
	if (nnam % 400 == 0 || nnam % 4 == 0 && nnam % 100 != 0)
	{
		return true;
	}
	return false;
}

int Tinhsongay(int nthang, int nnam)
{
	int songay = 0;
	switch (nthang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		songay = 31;
		break;
	case 4: case 6: case 9: case 11:
		songay = 30;
		break;
	case 2:
		if (IsNamnhuan(nnam))
			songay = 29;
		else
			songay = 28;
		break;
	}
	return songay;
}

bool Ktngayhople(NTN ntn)
{
	if (ntn.nam <= 0)
		return false;
	if (ntn.thang <= 0 || ntn.thang > 12)
		return false;
	if (ntn.ngay <= 0 || ntn.ngay > Tinhsongay(ntn.thang, ntn.nam))
		return false;
	return true;
}

void Nhap1quyensach(Sach& s)
{
	cout << "Nhap ten sach: ";
	cin.get(s.tensach, 21);
	cin.ignore();
	cout << "Nhap ten tac gia: ";
	cin.get(s.tentacgia, 21);
	cin.ignore();
	cout << "Nhap ngay thang nam xuat ban: ";
	NTN ngay;
	cin >> ngay.ngay;
	cin.ignore();
	cin >> ngay.thang;
	cin.ignore();
	cin >> ngay.nam;
	
	if (Ktngayhople(ngay) == true)
	{
		s.tgxuatban = ngay;
	}
	else
		cout << "Ngay thang nam ko hop le!\n";
}

void Xuat1quyensach(Sach s)
{
	cout << "++++++++++++++++++++++++++\n";
	cout << "Ten sach: " << s.tensach << endl;
	cout << "Ten tac gia: " << s.tentacgia << endl;
	cout << "Ngay thang nam xuat ban: " << s.tgxuatban.ngay << "/" << s.tgxuatban.thang << "/" << s.tgxuatban.nam << endl;
}

void Nhap50quyen(DsS &ds)
{
	cout << "Nhap so luong quyen sach: ";
	cin >> ds.n;
	while (ds.n < 1 || ds.n >50)
	{
		cout << "Vuot qua pham vi cho phep!\nVui long nhap lai!\n";
		cout << "Nhap so luong quyen sach: ";
		cin >> ds.n;
	}
	for (int i = 0; i < ds.n; i++)
	{
		cin.ignore();
		Nhap1quyensach(ds.sach[i]);
	}
}

void Xuat50quyen(DsS ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		Xuat1quyensach(ds.sach[i]);
	}
}

void XuatquyenTD(DsS ds, const char ntentacgia[] = "Tran Dung")
{
	for (int i = 0; i < ds.n; i++)
	{
		if (strcmp(ds.sach[i].tentacgia, ntentacgia) == 0)
		{
			Xuat1quyensach(ds.sach[i]);
		}
	}
}

int main() {
	Sach s;
	DsS sach;
	/*Nhap1quyensach(s);
	Xuat1quyensach(s);*/

	Nhap50quyen(sach);
	cout << "           DS sach\n";
	Xuat50quyen(sach);

	cout << "Thong tin quyen sach cua tac gia Tran Dung: \n";
	XuatquyenTD(sach);

	system("pause");
	return 0;
}