#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int sm, limit;	cin >> sm >> limit;
	vector<int> ans;
	vector<array<int, 2>> v;
	for (int x = 1; x <= limit; ++x)
		v.push_back({x & -x, x});

	sort(v.rbegin(), v.rend());
	for (auto &[lsb, val]: v) if (lsb <= sm)
		sm -= lsb, ans.push_back(val);

	if (sm) cout << -1;
	else {
		cout << (int)ans.size() << el;
		for (auto& x: ans) cout << x << ' ';
	} return 0;
}
