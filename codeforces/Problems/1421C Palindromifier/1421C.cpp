#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	cout << 3 << el;
	cout << "R " << s.size() - 1 << el;
	cout << "L " << s.size() << el;
	cout << "L " << 2 << el;
	return 0;
}
