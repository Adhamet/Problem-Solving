#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int oo = 1e18+7;

int n;
vector<int> a;
vector<int> pref;
vector<vector<int>> mem;

int recurse(int l, int r) {
	if (l >= r) return 0;
	int &ret = mem[l][r];
	if (~ret) return ret;

	ret = oo;
	for (int i = l; i < r; ++i) ret = min(ret, recurse(l, i) + recurse(i + 1, r));
	return ret += (pref[r] - (l ? pref[l - 1]: 0));
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	a.resize(n);
	pref.resize(n);
	mem.assign(n, vector<int>(n, -1));

	for (int i = 0; i < n; ++i) cin >> a[i];

	pref[0] = a[0];
	for (int i = 1; i < n; ++i) pref[i] = pref[i - 1] + a[i];

	return cout << recurse(0, n - 1), 0;
}
