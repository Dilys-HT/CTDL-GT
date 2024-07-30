#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct NTN
{
	int ngay, thang, nam;
};

struct Lop
{
	string malop;
	string tenlop;
	string tenkhoa;
	int sosv;
	NTN ngkg;
};

struct DSL
{
	Lop* ds;
	int n;
};

// KT ngay thang nam hop le ko
bool IsNamnhuan(int nnam)
{
	if (nnam % 400 == 0 || nnam % 100 != 0 && nnam % 4 == 0)
	{
		return true;
	}
	return false;
}

int Songay(int nthang, int nnam)
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
		if (IsNamnhuan(nnam) == true)
		{
			songay = 29;
		}
		else
		{
			songay = 28;
		}
		break;
	}
	return songay;
}

bool Ktngay(NTN nngay)
{
	if (nngay.nam < 1)
		return false;
	if (nngay.thang < 1 || nngay.thang >12)
		return false;
	if (nngay.ngay < 1 || nngay.ngay > Songay(nngay.thang, nngay.nam))
		return false;
	return true;
}

// Nhap 1 lop hoc
void Nhap1lop(Lop& l)
{
	cout << "+++++++++++++++++++++++++++++++\n";
	cout << "Nhap ma lop: ";
	getline(cin, l.malop);
	cout << "Nhap ten lop: ";
	getline(cin, l.tenlop);
	cout << "Nhap ten khoa: ";
	getline(cin, l.tenkhoa);
	cout << "Nhap so luong sinh vien: ";
	cin >> l.sosv;
	NTN ng;
	cout << "Nhap ngay khai giang:\n";
	cout << "Nhap ngay: ";
	cin >> ng.ngay;
	cin.ignore();
	cout << "Nhap thang: ";
	cin >> ng.thang;
	cin.ignore();
	cout << "Nhap nam: ";
	cin >> ng.nam;
	if (Ktngay(ng) == true)
	{
		l.ngkg = ng;
	}
	else
	{
		cout << "  Ngay khai giang khong hop le!\n";
	}
}

void Xuat1lop(Lop l)
{
	cout << "===============================\n";
	cout << "Ma lop: " << l.malop << endl;
	cout << "Ten lop: " << l.tenlop << endl;
	cout << "Ten khoa: " << l.tenkhoa << endl;
	cout << "So sinh vien: " << l.sosv << endl;
	cout << "Ngay khai giang: " << l.ngkg.ngay << "/" << l.ngkg.thang << "/" << l.ngkg.nam << endl;
}

// Nhap nhieu lop
void Nhapdslop(DSL& nlop)
{
	cout << "Nhap so luong lop can nhap: ";
	cin >> nlop.n;
	while (nlop.n < 1)
	{
		cout << "Loi! Vui long nhap lai!\n";
		cout << "Nhap so luong lop can nhap: ";
		cin >> nlop.n;
	}
	
	nlop.ds = new Lop[nlop.n];

	for (int i = 0; i < nlop.n; i++)
	{
		cin.ignore();
		Nhap1lop(nlop.ds[i]);
	}
}

void Xuatdslop(DSL nlop)
{
	for (int i = 0; i < nlop.n; i++)
	{
		Xuat1lop(nlop.ds[i]);
	}
}

// Doc tu File
void Nhaptufile(DSL& nlop)
{
	ifstream myfile("DSLop.txt");
	if (myfile.is_open())
	{
		myfile >> nlop.n;
		myfile.ignore();
		nlop.ds = new Lop[nlop.n];
		for (int i = 0; i < nlop.n; i++)
		{
			getline(myfile,nlop.ds[i].malop, '#');
			getline(myfile,nlop.ds[i].tenlop, '#');
			getline(myfile,nlop.ds[i].tenkhoa, '#');
			myfile >> nlop.ds[i].sosv;
			myfile.ignore();
			NTN ng;
			myfile >> ng.ngay;
			myfile.ignore();
			myfile >> ng.thang;
			myfile.ignore();
			myfile >> ng.nam;
			if (Ktngay(ng) == true)
			{
				nlop.ds[i].ngkg = ng;
			}
			else
			{
				cout << "  Ngay khai giang khong hop le!\n";
			}
			myfile.ignore();
		}
		myfile.close();
	}
	else
	{
		cout << "Mo file khong thanh cong!\n";
	}
}

void HuyCPD(DSL& nlop)
{
	delete[]nlop.ds;
	nlop.ds = NULL;
}

// Tong sv thuoc Khoa CNTT
int TongCNTT(DSL nlop)
{
	int tong = 0;
	for (int i = 0; i < nlop.n; i++)
	{
		if (nlop.ds[i].tenkhoa == "Khoa CNTT")
		{
			tong += nlop.ds[i].sosv;
		}
	}
	return tong;
}

// Dem co bn lop khoa NN
int DemNN(DSL nlop)
{
	int count = 0; 
	for (int i = 0; i < nlop.n; i++)
	{
		if (nlop.ds[i].tenkhoa == "Khoa NN")
		{
			count++;
		}
	}
	return count;
}

// Xoa 1 lop
void Xoa1lop(DSL& nlop, string malop)
{
	for (int i = 0; i < nlop.n; i++)
	{
		if (nlop.ds[i].malop == malop)
		{
			for (int j = i; j < nlop.n - 1; j++)
			{
				nlop.ds[j] = nlop.ds[j + 1];
			}
			nlop.n--;
		}
	}
}

// Xoa lop thuoc khoa CO BAN
void XoaCB(DSL& nlop)
{
	for (int i = 0; i < nlop.n; i++)
	{
		if (nlop.ds[i].tenkhoa == "Khoa CB")
		{
			for (int j = i; j < nlop.n - 1; j++)
			{
				nlop.ds[j] = nlop.ds[1 + j];
			}
			nlop.n--;
		}
	}
}

// Ghi cac lop thuoc khoa KT&QLC vao file
void GhiKTQLCfile(DSL& nlop)
{
	int count = 0;
	ifstream myfile("DSLop.txt");
	if (myfile.is_open())
	{
		for (int i = 0; i < nlop.n; i++)
		{
			if (nlop.ds[i].tenkhoa == "Khoa KTQLC")
			{
				count++;
			}
		}
		ofstream infile("KTQLC.txt");
		if (infile.is_open())
		{
			infile << count << endl;
			for (int j = 0; j < nlop.n; j++)
			{
				if (nlop.ds[j].tenkhoa == "Khoa KTQLC")
				{
					infile << nlop.ds[j].malop << "#" << nlop.ds[j].tenlop
						<< "#" << nlop.ds[j].tenkhoa << "#" << nlop.ds[j].sosv
						<< "#" << nlop.ds[j].ngkg.ngay << "/" << nlop.ds[j].ngkg.thang
						<< "/" << nlop.ds[j].ngkg.nam << endl;
				}
			}
			infile.close();
		}
		else
		{
			cout << "Mo file KTQLC.txt Khong thanh cong1\n";
		}
		myfile.close();
	}
	else
	{
		cout << "Mo file DSLop.txt Khong thanh cong!\n";
	}
}

int main() {
	Lop lop;
	DSL nlop;
	int op = 0;
	bool check = true;
	while (check == true)
	{
		cout << "\n                       MENU\n\n";
		cout << "1. Nhap nhieu lop tu ban phim\n";
		cout << "2. Xuat thong tin nhieu lop tu file\n";
		cout << "3. Tong so luong sinh vien cua KHOA CNTT\n";
		cout << "4. So luong lop cua KHOA NN\n";
		cout << "5. Xoa 1 lop bat ky\n";
		cout << "6. Xoa lop thuoc KHOA CB\n";
		cout << "7. Ghi vao file cac lop thuoc KHOA KT&QLC\n";
		cout << "     Nhan 1 phim bat ky de ket thuc chuong trinh\n\n";
		cout << "====> LUA CHON CUA BAN: ";
		cin >> op;
		cout << endl;
		switch (op)
		{
		case 1:
		{
			Nhapdslop(nlop);
			Xuatdslop(nlop);
			break;
		}
		case 2:
		{
			Nhaptufile(nlop);
			Xuatdslop(nlop);
			break;
		}
		case 3:
		{
			Nhaptufile(nlop);
			cout << "So luong sinh vien thuoc khoa CNTT: " << TongCNTT(nlop) << endl;
			break;
		}
		case 4:
		{
			Nhaptufile(nlop);
			cout << "So luong lop thuoc khoa NN: " << DemNN(nlop) << endl;
			break;
		}
		case 5:
		{
			Nhaptufile(nlop);
			string malop;
			cin.ignore();
			cout << "Nhap ma lop can xoa: ";
			getline(cin, malop);
			cout << "\n               DS sau khi xoa lop " << malop << endl;
			Xoa1lop(nlop, malop);
			Xuatdslop(nlop);
			break;
		}
		case 6:
		{
			Nhaptufile(nlop);
			cout << "\n               DS sau khi xoa cac lop thuoc khoa CO BAN \n";
			XoaCB(nlop);
			Xuatdslop(nlop);
			break;
		}
		case 7:
		{
			Nhaptufile(nlop);
			GhiKTQLCfile(nlop);
			break;
		}
		default:
		{
			check = false;
			break;
		}
		}
	}

	HuyCPD(nlop);
	system("pause");
	return 0;
}