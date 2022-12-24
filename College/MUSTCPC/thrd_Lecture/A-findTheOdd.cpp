#include <iostream>
#include <map>
using namespace std;
 
int main()
{
	map<int, int> mp;
	int numE, tmp;
	cin >> numE;
 
	for (int i = 0; i < numE; i++)
	{
		cin >> tmp;
		mp[tmp]++;
	}
 
	for (auto pair : mp)
		if (pair.second % 2 != 0) cout << pair.first;
}