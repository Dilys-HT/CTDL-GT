#include<iostream>
#include <string>
using namespace std;

struct PhongBan
{
	string maPhongBan;
	string tenPhongBan;
};

void Nhap(PhongBan& pb)
{
	cout << "Nhap ma phng ban: ";
	cin >> pb.maPhongBan;
	cin.ignore();
	cout << "Nhap ten phng ban: ";
	getline(cin, pb.tenPhongBan);
}

void Xuat(PhongBan pb)
{
	cout << "Ma phong ban: " << pb.maPhongBan << endl;
	cout << "Ten phong ban: " << pb.tenPhongBan << endl;
}

int main() {
	PhongBan pb;
	Nhap(pb);
	Xuat(pb);

	system("pause");
	return 0;
}