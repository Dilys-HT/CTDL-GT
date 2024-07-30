// Dem so ky tu co trong chuoi o file BT4.txt va xuat so luong ra man hinh
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
	int count = 0;
	char chuoi[] = { 0 };

	ifstream myFile("BT4.txt");
	if (myFile.is_open())
	{
		while (myFile.eof() == false)
		{
			myFile >> chuoi[count];
			count++;
			myFile.ignore();
		}
		cout << "Co " << count << " ky tu trong chuoi!\n";
		myFile.close();
	}
	else
	{
		cout << "Mo file ko thanh cong!\n";
	}


	system("pause");
	return 0;
}