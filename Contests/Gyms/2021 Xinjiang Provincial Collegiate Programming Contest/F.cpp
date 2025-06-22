#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	vector<i64> p;
	vector<pair<i64,i64>> a;
	for (int i = 0; i < n; ++i) {
		i64 pos, dir; cin >> pos >> dir;
		if (dir == 1) p.push_back(pos+k);
		else if (dir == -1) p.push_back(pos-k);
		else p.push_back(pos);
		a.push_back({pos, i});
	}

	vector<i64> ans(n);
	sort(a.begin(), a.end()), sort(p.begin(), p.end());
	for (int i = 0; i < n; ++i) ans[a[i].second] = p[i];
	for (int i = 0; i < n; ++i) {
		if (i != 0) cout << ' ';
		cout << ans[i];
	}

	return 0;
}
