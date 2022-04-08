#include <iostream>
#include <string>
using namespace std;

struct coords {
	pair<int, int>p1, p2, p3, p4;
}rect;

int main()
{
	cout << "Enter point 1: ", cin >> rect.p1.first >> rect.p1.second;
	cout << "Enter point 4: ", cin >> rect.p4.first >> rect.p4.second;
	int length = abs(rect.p1.first - rect.p4.first);
	int width = abs(rect.p1.second - rect.p4.second);
	cout << "Area is: " << length * width;
}