#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;  std::cin >> n;
	std::vector<i64> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	int mn = *std::min_element(a.begin(), a.end());

	int mxIdx = std::max_element(a.begin(), a.end()) - a.begin();
	int idx = mxIdx;

	bool goingToInc = false, gotToIt = false;
	i64 mx = mn, ans1 = 0;

	while (!gotToIt) {
		ans1 += (goingToInc ? mx : a[idx]);

		if (goingToInc) mx = std::max(mx, a[idx]);
		if (a[idx] == mn) goingToInc = true;

		idx = (idx - 1 + n) % n;
		if (idx == mxIdx) gotToIt = true;
	}
	ans1 = (ans1 + mx - (mn==0? 0: mn+1));

	goingToInc = false;
	gotToIt = false;
	mx = mn;
	idx = mxIdx;
	i64 ans2 = 0;
	while (!gotToIt) {
		ans2 += (goingToInc ? mx : a[idx]);

		if (goingToInc) mx = std::max(mx, a[idx]);
		if (a[idx] == mn) goingToInc = true;

		idx = (idx + 1) % n;
		if (idx == mxIdx) gotToIt = true;
	}
	ans2 = (ans2 + mx - (mn==0? 0: mn+1));

	std::cout << std::min(ans1, ans2) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;  std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

