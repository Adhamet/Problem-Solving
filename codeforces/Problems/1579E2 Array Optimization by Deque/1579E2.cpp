#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 4e5+5;
int t[4*MAXN], sz;

void build(int v = 1, int tl = 0, int tr = sz - 1) {
	t[v] = 0;
	if (tl == tr) return;
	int tm = (tl + tr) >> 1;
	build(v*2, tl, tm);
	build(v*2+1, tm+1, tr);
}

void update(int pos, int v = 1, int tl = 0, int tr = sz - 1) {
	if (tl == tr) t[v] += 1;
	else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm) update(pos, v*2, tl, tm);
		else update(pos, v*2+1, tm+1, tr);
		t[v] = t[v*2] + t[v*2+1];
	}
}

int query(int l, int r, int v = 1, int tl = 0, int tr = sz - 1) {
	if (l > r) return 0;
	if (tl == l && tr == r) return t[v];
	int tm = (tl + tr) >> 1;
	return query(l, min(r, tm), v*2, tl, tm) +
		query(max(l, tm+1), r, v*2+1, tm+1, tr);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<int> a(n), comp;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			comp.push_back(a[i]);
		}

		sort(comp.begin(), comp.end());
		comp.erase(unique(comp.begin(), comp.end()), comp.end());
		sz = (int)comp.size();

		unordered_map<int, int> compress;
		for (int i = 0; i < sz; ++i) compress[comp[i]] = i;

		build();
		i64 ans = 0;
		for (int i = 0; i < n; ++i) {
			int x = compress[a[i]];
			ans += min(query(0, x - 1), query(x + 1, sz - 1));
			update(x);
		}

		cout << ans << el;
	}

	return 0;
}

