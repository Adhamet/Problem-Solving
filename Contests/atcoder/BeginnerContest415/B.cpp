#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;	cin >> s;
	int n = (int)s.size();
	vector<int> c;
	for (int i = 0; i < n; ++i) 
		if (s[i] == '#') c.push_back(i + 1);
	for (int i = 0; i < (int)c.size(); i+=2)
		cout << c[i] << ',' << c[i+1] << el;
	return 0;
}
