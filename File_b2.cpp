#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int m = 0;

	ifstream myFile("BT1.txt");
	if (myFile.is_open())
	{
		myFile >> m;
		cout << m << endl;
		myFile.close();
	}
	else
	{
		cout << "Mo file ko thanh cong!\n";
	}
	system("pause");
	return 0;
}