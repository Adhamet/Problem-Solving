#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	int ans = -accumulate(a.begin(), a.end(), 0LL);
	for (int i = 0; i < 30; i++) {
		int s = 0;
		vector<int> pref = {1, 0};
		for (auto x: a) {
			s ^= ((x >> i) & 1);
			ans += pref[s ^ 1] * 1LL << i;
			pref[s] += 1;
		}
	}

	return cout << ans, 0;
}
