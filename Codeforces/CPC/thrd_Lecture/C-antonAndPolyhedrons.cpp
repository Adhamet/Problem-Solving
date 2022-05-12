#include <iostream>
#include <map>
#include <string>
using namespace std;
 
int main()
{
	int num, totalF = 0;
	string str;
	map<string, int> polys;
	
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> str;
		if (str == "Tetrahedron") polys[str] = 4;
		else if (str == "Cube") polys[str] = 6;
		else if (str == "Octahedron") polys[str] = 8;
		else if (str == "Dodecahedron") polys[str] = 12;
		else if (str == "Icosahedron") polys[str] = 20;
		totalF += polys[str];
	}
 
	cout << totalF;
}