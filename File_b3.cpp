#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int x = 8, y = 3, z = 2;
	int a = 0, b = 0, c = 0;
	double aver = 0;

	ofstream myFile("BT3.txt");
	if (myFile.is_open())
	{
		myFile << x << "#" << y << "#" << z << endl;
		myFile.close();
	}
	else
	{
		cout << "Mo file ko thanh cong!\n";
	}

	ifstream myfile("BT3.txt");
	if (myfile.is_open())
	{
		myfile >> a;
		myfile.ignore();
		myfile >> b;
		myfile.ignore();
		myfile >> c;
		aver = (a + b + c) / 3.0;
		cout << "Trung binh cong cua 3 so nguyen: " << aver << endl;
		myfile.close();
	}
	else
	{
		cout << "Mo file ko thanh cong!\n";
	}
	system("pause");
	return 0;
}