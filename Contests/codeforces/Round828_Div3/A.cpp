#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &i: a) cin >> i;
		
		string s;
		cin >> s;

		map<int, set<char>> mp;
		for (int i = 0; i < n; i++) mp[a[i]].insert(s[i]);
		bool acc = true;
		for (auto itm: mp) if (itm.second.size() > 1) {
			acc = false;
			break;
		}

		cout << (acc? "YES": "NO") << el;
	}
	return 0;
}
