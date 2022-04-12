#include <iostream>
using namespace std;

void init2D(int row, int col, int arra[5][5]) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> arra[i][j];
}

void maxPerRow(int row, int col, int arra[5][5]) {
	int max = arra[0][0];
	for (int i = 0; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (max < arra[i][j])
				max = arra[i][j];
		}
		cout << "#row" << i + 1 << " : " << max;
	}
}

int main()
{
	int r, c;
	cout << "Enter number of rows: ", cin >> r;
	cout << "Enter number of columns: ", cin >> c;
	int arr[5][5];
	cout << "Enter matrix elements: ";
	init2D(r, c, arr);
	
	cout << "The maximum in each row is: ";
	maxPerRow(r, c, arr);
}