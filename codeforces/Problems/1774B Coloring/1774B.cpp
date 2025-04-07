#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define i32 int32_t
#define i64 int64_t

int32_t main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	i32 tc;
	cin >> tc;

	while (tc--) {
		i64 n, m, k;
		cin >> n >> m >> k;

		vector<i64> a(m);
		for (int i = 0; i < m; ++i) cin >> a[i];
		sort(a.begin(), a.end(), greater<>());

		i64 xgrps = n % k;
		bool acc = true;
		for (int i = 0; i < m; ++i) {
			if (xgrps) a[i] -= 1, xgrps -= 1;
			if (a[i] > (n / k)) {
				acc = false;
				break;
			}
		}

		cout << (acc ? "YES" : "NO") << el;
	}

	return 0;
}
