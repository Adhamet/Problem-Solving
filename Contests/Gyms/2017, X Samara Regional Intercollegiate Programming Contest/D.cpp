#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, x;	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int g = a[0];
	for (int i = 1; i < n; ++i) g = __gcd(g, a[i]);
	if (x%g == 0) cout << "YES";
	else cout << "NO";
	return 0;
}
