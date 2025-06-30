#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	i64 n;	cin >> n;
	vector<i64> divs;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			divs.push_back(i);
			if (i != (n / i))
				divs.push_back(n / i);
		}
	}

	vector<i64> ans;
	for (auto& d: divs) {
		i64 last	= 1 + n - d;
		i64 cnt	= n / d;
		ans.push_back(cnt * (1 + last) / 2);
	}

	sort(ans.begin(), ans.end());
	for (auto &x: ans) cout << x << ' ';
	return 0;
}
