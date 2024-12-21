#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end());
	
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (a[i].second >= ans) ans = a[i].second;
		else ans = a[i].first;
	}

	return cout << ans, 0;
}
