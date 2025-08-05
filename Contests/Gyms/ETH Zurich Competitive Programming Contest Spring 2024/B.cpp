#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int M = 1e9 + 7;

i64 binexp(i64 b, i64 e) {
	i64 r = 1;
	b %= M;
	while (e) {
		if (e & 1) r = (r * b) % M;
		b = (b * b) % M;
		e >>= 1;
	}
	return r;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int M = 1e9 + 7;

	int n;	cin >> n;
	vector<int> deg(n);
	for (int i = 0, u, v; i < n - 1; ++i) {
		cin >> u >> v;
		--u, --v;
		deg[u]++, deg[v]++;
	}

	i64 ans = n - 1;

	for (int i = 0; i < n; ++i) if (deg[i] >= 2) {
		ans = (ans + ((1LL * deg[i] * (deg[i] - 1)) / 2) % M) % M;
	}

	return cout << ans, 0;
}
