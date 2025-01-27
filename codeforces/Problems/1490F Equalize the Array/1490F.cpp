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
		int n;
		cin >> n;
		unordered_map<int, int> freq;
		for (int i = 0, x; i < n; ++i) {
			cin >> x;
			freq[x] += 1;
		}

		vector<int> fFreq;
		for (auto f: freq) fFreq.push_back(f.second);
		sort(fFreq.begin(), fFreq.end());
		int mxKept = 0;
		for (int i = 0, m = (int)fFreq.size(); i < m; ++i) {
			int F = fFreq[i], cnt = m - i;
			mxKept = max(mxKept, F * cnt);
		}

		cout << n - mxKept << el;
	}

	return 0;
}
