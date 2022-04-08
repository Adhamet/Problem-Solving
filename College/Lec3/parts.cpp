#include <iostream>
#include <string>
using namespace std;

int main()
{
	int PNum, PQ, PP;
	string PName;

	cout << "Enter part number: ", cin >> PNum;
	cout << "Part Name: ", cin >> PName;
	cout << "Part Quantity: ", cin >> PQ;
	cout << "Part Price: ", cin >> PP;

	cout << PP * PQ;
}