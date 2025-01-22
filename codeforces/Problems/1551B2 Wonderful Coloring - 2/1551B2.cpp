#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int>	a(n);
		map<int, int> freq;
		vector<array<int, 2>> vec;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			freq[a[i]] += 1;
			if (freq[a[i]] <= k) vec.push_back({a[i], i});
		}

		sort(vec.begin(), vec.end());

		int m = (vec.size() / k) * k;
		vector<int> ans(n);
		for (int i = 0; i < m; ++i) ans[vec[i][1]] = (i % k) + 1;
		for (auto num: ans) cout << num << ' ';
		cout << el;
	}

	return 0;
}
