#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x = 1;
		cin >> n;

		set<int> st[n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				char c;
				cin >> c;
				if (c == '1') st[i].insert(x), st[j].insert(x);
				else st[i].insert(x);
			}

			x += 1;
		}

		for (int i = 0; i < n; ++i) {
			cout << st[i].size() << " ";
			for (auto ele: st[i]) cout << ele << " ";
			cout << el;
		}
	}

	return 0;
}
