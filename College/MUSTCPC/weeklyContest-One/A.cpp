#include <iostream>
#include <string>
using namespace std;
 
int main()
{
	string s;
	int n, As, Bs, Cs;
	cin >> n;
 
	for (int i = 0; i < n; i++)
	{
		As = 0, Bs = 0, Cs = 0;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == 'A')
				As++;
			else if (s[j] == 'C')
				Cs++;
			else if (s[j] == 'B')
				Bs++;
		}
 
		if (Cs + As == Bs) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}