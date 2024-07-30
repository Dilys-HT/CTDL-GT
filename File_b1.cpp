#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int a = 0, b = 0;
	int tong = 0;
	cout << "Nhap 2 so nguyen: \n" << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	
	tong = a + b;
	cout << "Tong 2 so " << a << ", " << b << ": " << tong << endl;

	ofstream myFile("BT1.txt");
	if (myFile.is_open())
	{
		myFile << tong;
		myFile.close();
	}
	else
	{
		cout << "Mo file ko thanh cong!\n";
	}

	system("pause");
	return 0;
}