#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int m, s;
		cin >> m >> s;

		int mx = 0;
		map<int, bool> exist;
		for (int i = 0, x; i < m; i++) {
			cin >> x;
			exist[x] = true;
			mx = max(mx, x);
		}

		int i = 1;
		ll tot = 0;
		while (tot < s) {
			if (!exist[i]) tot += i, exist[i] = true;
			mx = max(mx, i++);
		}

		bool acc = true;
		for (int i = 1; i <= mx; i++) if (!exist[i]) {
			acc = false;
			break;
		}

		cout << (acc && tot == s ? "YES" : "NO") << el;
	}

	return 0;
}
