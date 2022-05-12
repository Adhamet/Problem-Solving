#include <iostream>
#include <map>
#include <string>
using namespace std;
 
int main()
{
	int l, most = 0;
	string s;
	map<string, int> mp;
 
	cin >> l >> s;
 
	for (int i = 1; i < s.length(); i++)
	{
		string substring = s.substr(i - 1, 2);
		mp[substring]++;
	}
 
	string twoG;
	for (auto &kv : mp)
	{
		if (most < kv.second) {
			most = kv.second;
			twoG = kv.first;
		}
	}
 
	cout << twoG;
}