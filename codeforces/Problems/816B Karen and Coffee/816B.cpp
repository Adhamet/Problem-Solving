#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	const int MAXN = 2e5 + 5;
	int n, k, q;
	cin >> n >> k >> q;
	
	vector<int> diff(MAXN);
	for (int i = 0, l, r; i < n; ++i) {
		cin >> l >> r;
		diff[l] += 1, diff[r + 1] -= 1;
	}

	for (int i = 1; i < MAXN; ++i) diff[i] += diff[i - 1];
	for (int i = 1; i < MAXN; ++i) diff[i] = (diff[i] >= k? 1: 0);
	for (int i = 1; i < MAXN; ++i) diff[i] += diff[i - 1];
	
	int l, r;
	while (q--) {
		cin >> l >> r;
		cout << diff[r] - diff[l - 1] << el;
	}

	return 0;
}
