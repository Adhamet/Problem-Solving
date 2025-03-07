#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	while (cin >> n && n != -1) {
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());

		int sz = 
	}

	return 0;
}
