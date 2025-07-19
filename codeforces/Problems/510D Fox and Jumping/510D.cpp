#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

constexpr int MXN = 305;
constexpr i64 oo = 1e18;

i64 n, a[MXN], c[MXN];
map<pair<i64,i64>, i64> mem;

i64 go(int idx, i64 g) {
	if (idx == n) return (g==1)? 0: oo;
	if (mem.count({idx,g})) return mem[{idx,g}];
	return mem[{idx,g}] = min(go(idx + 1, g), go(idx + 1, __gcd(g, a[idx])) + c[idx]);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> c[i];
	i64 ans = go(0,0);
	return cout << (ans == oo? -1: ans), 0;
}
