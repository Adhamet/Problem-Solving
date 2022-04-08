#include <iostream>
using namespace std;

struct date {
	int day, month, year;
};

struct student {
	int ID, grades[6], total;
	string name;
	date dOfBirth;
}st[10];

int main()
{
	int students;
	cout << "Enter number of students(Max is 10): ", cin >> students;
	
	for (int i = 0; i < students; i++)
	{
		cout << "Enter Student ID: ", cin >> st[i].ID;

		cout << "Enter Student Name: ", cin >> st[i].name;

		cout << "Enter date of birth(D/M/Y): ", cin >> st[i].dOfBirth.day >> st[i].dOfBirth.month
			>> st[i].dOfBirth.year;

		cout << "Enter 6 grades for the student: ";
		for (int j = 0; j < 6; j++)
		{
			cin >> st[i].grades[j];
			st[i].total += st[i].grades[j];
		}
		cout << "Student #" << i + 1 << " " << st[i].total;
	}
}