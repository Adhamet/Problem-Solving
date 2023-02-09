
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	int alphabet1[26]{ 0 }, alphabet2[26]{ 0 };
	string str1, str2, input, total;
	cin >> str1 >> str2 >> input;
 
	total = str1 + str2;
	if (total.length() == input.length()) {
		for (int i = 0; i < input.length(); i++) {
			alphabet1[total[i] - 65]++;
			alphabet2[input[i] - 65]++;
		}
		for (int i = 0; i < 26; i++) {
			if (alphabet1[i] != alphabet2[i]) { return cout << "NO", 0; }
		}
		cout << "YES";
	}
	else cout << "NO";
}  