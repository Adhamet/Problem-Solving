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
		vector<int> a(n + 1, 0);
		for (int i = 1; i <= n; ++i) cin >> a[i];

		if (is_sorted(a.begin(), a.end())) cout << 0 << el;
		else {
			int firstNotOk = -1, lastNotOk = -1;
			bool allNotOk = true;
			for (int i = 1; i <= n; ++i) {
				if (a[i] != i) {
					if (firstNotOk == -1) firstNotOk = i;
					else lastNotOk = i;
				}
			}
			
			for (int i = firstNotOk; i <= lastNotOk; ++i) {
				if (a[i] == i) {
					allNotOk = false;
					break;
				}
			}

			cout << (allNotOk? 1: 2) << el;
		}
	}
	
	return 0;
}
