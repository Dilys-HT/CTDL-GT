
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
	char chuoi[21];
	
	cout << "Nhap chuoi toi da 20 ky tu: ";
	cin.get(chuoi, 21);

	char* pc = chuoi;
	
	ofstream myFile("BT4.txt");
	if (myFile.is_open())
	{
		while (*pc != '\0')
		{
			myFile << (char)toupper(*pc) << endl;
			pc++;
		}
		myFile.close();
	}
	else
	{
		cout << "Mo file ko thanh cong!\n";
	}

	system("pause");
	return 0;
}