#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define int i64
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n;	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	int ans = 0;
	unordered_map<int,int> f1,f2;
	for (int i = 0; i < n; ++i) {
		f1[a[i] + i]++;
		if (f1[i - a[i]]) ans += f1[i - a[i]];
	}
	
	return cout << ans, 0;
}
