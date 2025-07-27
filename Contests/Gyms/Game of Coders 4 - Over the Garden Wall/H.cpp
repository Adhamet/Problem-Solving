#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;	cin >> n;
	vector<i64> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	cout << accumulate(a.begin(), a.end(), 0LL);
	return 0;
}
