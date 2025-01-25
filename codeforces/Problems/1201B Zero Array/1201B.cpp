#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, sum = 0, mx = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}
	return cout << (sum%2!=0 || mx>sum/2? "NO": "YES"), 0;
}
