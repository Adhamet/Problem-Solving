#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;
		i64 k;	cin >> n >> k;
		vector<array<i64,3>> c(n);
		for (int i = 0; i < n; ++i)
			cin >> c[i][0] >> c[i][1] >> c[i][2];

		sort(c.begin(), c.end(), [](auto &a, auto &b) { return a[0] < b[0]; });

		priority_queue<pair<i64,int>> pq;
		int idx = 0;
		i64 cur = k;
		while (true) {
			while (idx < n && c[idx][0] <= cur) {
				pq.push({c[idx][2], idx});
				++idx;
			}

			if (pq.empty()) break;

			auto [cureal, iidx] = pq.top();
			pq.pop();

			if (c[iidx][2] < cur) continue;
			cur = cureal;
		}

		cout << cur << el;
	}

	return 0;
}
