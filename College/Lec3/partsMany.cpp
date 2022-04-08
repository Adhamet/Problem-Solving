#include <iostream>
#include <string>
using namespace std;

int totalPrice(int quantity, int price) {
	int total = quantity * price;
	return total;
}

int main()
{
	int total = 0;
	for (int i = 0; i < 5; i++) {
		int PNum, PQ, PP;
		string PName;
		cout << "Part number #" << i + 1;
		cout << "Enter part number: ", cin >> PNum;
		cout << "Part Name: ", cin >> PName;
		cout << "Part Quantity: ", cin >> PQ;
		cout << "Part Price: ", cin >> PP;
		cout << endl;
		total += totalPrice(PQ, PP);
	}
	cout << total;
}