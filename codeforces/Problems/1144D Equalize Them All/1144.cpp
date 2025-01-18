#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	map<int, int> freq;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		freq[a[i]] += 1;
	}

	vector<int> x = a;
	int mxVal = 0, mxNum = 0;
	for (auto num: freq) {
		if (num.second > mxVal) {
			mxVal = num.second;
			mxNum = num.first;
		}
	}

	vector<int> indices;
	for (int i = 0; i < n; ++i) if (a[i] == mxNum) {
		indices.push_back(i);
	}

	vector<pair<int, int>> ans;
	for (auto idx: indices) {
		int l = idx - 1, r = idx + 1;
		while (l >= 0 && a[l] != mxNum) ans.push_back({l, l + 1}), a[l] = mxNum, l -= 1;
		while (r < n && a[r] != mxNum) ans.push_back({r, r - 1}), a[r] = mxNum, r += 1;
	}

	cout << ans.size() << el;
	for (auto pr: ans) {
		if (x[pr.first] < mxNum) cout << "1 " << pr.first + 1 << " " << pr.second + 1 << el;
		else cout << "2 " << pr.first + 1 << " " << pr.second + 1 << el;
	}

	return 0;
}
