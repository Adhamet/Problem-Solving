#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int k;
	cin >> k;
	vector<array<int, 3>> info;
	for (int i = 0, n; i < k; ++i) {
		cin >> n;
		vector<int> a(n);
		for (int j = 0; j < n; ++j) cin >> a[j];

		int sum = accumulate(a.begin(), a.end(), 0);
		for (int j = 0; j < n; ++j) info.push_back({sum - a[j], i, j});
	}

	sort(info.begin(), info.end(), [&](auto a, auto b) { return a[0] < b[0]; });
	for (int i = 0, m = (int)info.size(); i < m - 1; ++i) {
		if (info[i][0] == info[i + 1][0] && (info[i][1] != info[i + 1][1])) {
			cout << "YES" << el;
			cout << info[i + 1][1] + 1 << ' ' << info[i + 1][2] + 1 << el;
			cout << info[i][1] + 1 << ' ' << info[i][2] + 1;
			exit(0);
		}
	}

	return cout << "NO", 0;
}
