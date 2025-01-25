#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	auto steps = [](int l, int r) {
		int cnt = 0;
		while (l < r) cnt += (r - l), l /= 10, r /= 10;
		return cnt;
	};

	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		cout << steps(l, r) << el;
	}
	return 0;
}
