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
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		bool acc = false;
		for (int i = 0; i < n - 1; i++) {
			int a = v[i], b = v[i], c = v[i];
			if (a + b > c && b + c > a && a + c > b) {
				c = v[i  + 1];
				if (a + b > c && b + c > a && a + c > b) {
					b = v[i + 1];
					if (a + b > c && b + c > a && a + c > b) {
						a = v[i + 1];
						if (a + b > c && b + c > a && a + c > b) {
							acc = true;
							break;
						}
					}
				}
			}
		}

		cout << (acc? "YES": "NO") << el;
	}

	return 0;
}
