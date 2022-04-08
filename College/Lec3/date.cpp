#include <iostream>
using namespace std;

struct date {
	int day, month, year;
}d1;
int main()
{
	cout << "Enter day: ", cin >> d1.day;
	cout << "Enter month: ", cin >> d1.month;
	cout << "Enter year: ", cin >> d1.year;

	cout << "The date you entered is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
}