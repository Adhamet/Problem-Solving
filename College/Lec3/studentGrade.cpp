#include <iostream>
using namespace std;

struct date {
	int day, month, year;
};

struct student {
	int ID, grades[6], total;
	string name;
	date dOfBirth;
}st;

int main()
{
	cout << "Enter Student ID: ", cin >> st.ID;

	cout << "Enter Student Name: ", cin >> st.name;

	cout << "Enter date of birth(D/M/Y): ", cin >> st.dOfBirth.day >> st.dOfBirth.month
		                                        >> st.dOfBirth.year;

	cout << "Enter 6 grades for the student: ";
	for (int i = 0; i < 6; i++)
	{
		cin >> st.grades[i];
		st.total += st.grades[i];
	}
	
	cout << "Total grade is: " << st.total;
}