#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'
#define debug(...)
/*#define debug(...) cerr << __VA_ARGS__ << el;*/

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	if (n > m) return cout << 0, 0;

	i64 ans = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ans = (ans * abs(a[i] - a[j])) % m;
		}
	}

	return cout << ans, 0;
}
