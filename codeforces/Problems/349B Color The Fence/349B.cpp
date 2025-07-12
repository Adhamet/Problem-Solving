#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define int i64
#define el '\n'

constexpr int MXN = 1e5+5;
int mn = 1e9, v;
int a[10], mem[MXN];

int solve(int x) {
	if (x < mn) return 0;

	int &ret = mem[x];
	if (~ret) return ret;
	ret = 0;

	for (int i = 9; i >= 1; --i) if (x - a[i] >= 0)
		ret = max(ret, 1 + solve(x - a[i]));
	return ret;
}

void build(int x) {
	if (x < mn) return;
	for (int i = 9; i >= 1; --i) if (x - a[i] >= 0) {
		if (mem[x] == mem[x - a[i]] + 1) {
			cout << i;
			build(x - a[i]);
			return;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> v;
	for (int i = 1; i <= 9; ++i) {
		cin >> a[i];
		mn = min(mn, a[i]);
	}

	for (int i = 1; i <= 9; ++i) {
		if (a[i] >= mn) mem[i] = -1;
		else mem[i] = 0;
	}

	if (solve(v)) build(v);
	else cout << -1;
	return 0;
}
