#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 2e5+5;
int n, t[4*MAXN];

void update(int v, int tl, int tr, int pos) {
	if (tl == tr) t[v]++;
	else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm) update(v*2, tl, tm, pos);
		else update(v*2+1, tm+1, tr, pos);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int query(int v, int tl, int tr, int l, int r) {
	if (r < tl || l > tr) return 0;
	if (tl >= l && tr <= r) return t[v];
	int tm = (tl + tr) >> 1;
	return query(v*2,tl,tm,l,r) + query(v*2+1,tm+1,tr,l,r);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	vector<int> a(2*n);
	for (int i = 0; i < 2*n; ++i) cin >> a[i];

	vector<pair<int, int>> pos(n+1, {-1, -1});
	for (int i = 0; i < 2*n; ++i) {
		if (pos[a[i]].first == -1) pos[a[i]].first = i;
		else pos[a[i]].second = i;
	}

	vector<tuple<int, int, int>> intervals;
	for (int i = 1; i <= n; ++i) 
		intervals.emplace_back(pos[i].first, pos[i].second, i);

	sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
		return get<1>(a) < get<1>(b);
	});

	vector<int> ans(n+1, 0);
	for (auto [l, r, idx] : intervals) {
		ans[idx] = query(1, 0, 2*n-1, l+1, r-1);
		update(1, 0, 2*n-1, l);
	}
	
	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
	return 0;
}
