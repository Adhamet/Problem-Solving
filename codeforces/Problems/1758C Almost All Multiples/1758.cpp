#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, x;	cin >> n >> x;
		if (n % x) {
			cout << -1 << el;
			continue;
		}

		vector<int> p(n + 1);
		iota(p.begin(), p.end(), 0);
		p[n] = 1, p[1] = x;

		while (x < n) {
			for (int i = x * 2; i <= n; i += x) {
				if (n % i == 0) {
					p[x] = i;
					x = i;
					break;
				}
			}
		}

		for (int i = 1; i <= n; ++i) cout << p[i] << ' ';
		cout << el;
	}

	return 0;
}
