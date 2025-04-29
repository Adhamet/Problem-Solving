#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		i64 n;
		cin >> n;
		i64 a[n+1];
		for (int i = 0; i < n; ++i) cin >> a[i];
		vector<i64> prefMax(n+1, 0), suff(n+1,0);
		prefMax[0] = a[0], suff[n-1] = a[n-1], suff[n] = 0;
		for (int i = 1; i < n; ++i) prefMax[i] = max(prefMax[i-1], a[i]);
		for (int i = n-2; i >= 0; --i) suff[i] = suff[i+1] + a[i];
		for (int k = 0; k < n; ++k)
			cout << max(suff[n-k] + a[n-k-1], suff[n-k] + prefMax[n-k-1]) << ' ';
		cout << el;
	}

	return 0;
}	
