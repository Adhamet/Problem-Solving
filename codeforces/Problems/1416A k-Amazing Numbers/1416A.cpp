#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int64_t oo = 1e18+5;

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int32_t tc;
	cin >> tc;

	while (tc--) {
		int32_t n;
		cin >> n;
		vector<int32_t> a(n);
		vector<vector<int32_t>> pos(n + 1);

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			pos[a[i]].push_back(i);
		}

		vector<int64_t> mnK(n + 1, oo); // min K for each subsegment size
		for (int64_t x = 1; x <= n; ++x) {
			if (pos[x].empty()) continue;

			vector<int32_t> indices = {-1};
			indices.insert(indices.end(), pos[x].begin(), pos[x].end());
			indices.push_back(n);

			int32_t mxGap = 0;
			for (int32_t j = 1; j < indices.size(); ++j) 
				mxGap = max(mxGap, indices[j] - indices[j - 1]);
			mnK[mxGap] = min(mnK[mxGap], x);
		}

		for (int i = 1; i <= n; ++i) mnK[i] = min(mnK[i], mnK[i - 1]);
		for (int i = 1; i <= n; ++i) cout << (mnK[i] == oo ? -1 : mnK[i]) << ' ';
		cout << el;
	}

	return 0;
}
