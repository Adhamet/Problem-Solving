#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int k;
	cin >> k;
	map<int, array<int, 2>> last;
	unordered_set<int> st;
	for (int i = 0, n; i < k; ++i) {
		cin >> n;
		vector<int> a(n);
		map<int, int> indices;
		for (int j = 0; j < n; ++j) cin >> a[j], indices[a[j]] = j;

		int sum = accumulate(a.begin(), a.end(), 0);
		for (auto [_, j]: indices) {
			if (st.count(sum - a[j])) {
				cout << "YES" << el;
				cout << last[sum - a[j]][0] + 1 << ' ' << last[sum - a[j]][1] + 1 << el;
				cout << i + 1 << ' ' << j + 1;
				exit(0);
			} else st.insert(sum - a[j]), last[sum - a[j]][0] = i, last[sum - a[j]][1] = j;
		}
	}

	return cout << "NO", 0;
}
