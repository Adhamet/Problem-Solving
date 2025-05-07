#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 200005;
const i64 oo = 1e18 + 5;
int n;
struct Node {
	i64 lazy, mn;
};

Node t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
	if (tl == tr) t[v] = {0, a[tl]};
	else {
		int tm = (tl + tr) >> 1;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v].mn = min(t[v*2].mn, t[v*2+1].mn);
	}
}

void applyy(int v, int add) {
	t[v].mn += add;
	t[v].lazy += add;
}

void push(int v) {
	if (t[v].lazy) {
		applyy(v*2, t[v].lazy);
		applyy(v*2+1, t[v].lazy);
		t[v].lazy = 0;
	}
}

void update(int v, int tl, int tr, int l, int r, int val) {
	if (l > r || tl > r || tr < l) return;
	if (l <= tl && tr <= r) applyy(v, val);
	else { 
		push(v);
		int tm = (tl + tr) >> 1;
		update(v*2, tl, tm, l, r, val);
		update(v*2+1, tm+1, tr, l, r, val);
		t[v].mn = min(t[v*2].mn, t[v*2+1].mn);
	}
}

i64 query(int v, int tl, int tr, int l, int r) {
	if (l > r || tl > r || tr < l) return oo;
	if (l <= tl && tr <= r) return t[v].mn;
	push(v);
	int tm = (tl + tr) >> 1;
	return min(query(v*2, tl, tm, l, r),
			query(v*2+1, tm+1, tr, l, r));
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	build(a, 1, 0, n - 1);

	int m; cin >> m;
	cin.ignore();
	while (m--) {
		string line; getline(cin, line);
		stringstream ss(line);

		vector<int> args;
		int x;
		while (ss >> x) args.push_back(x);

		if (args.size() == 2) {
			int lf = args[0], rg = args[1];
			if (lf <= rg) cout << query(1, 0, n - 1, lf, rg) << el;
			else cout << min(query(1, 0, n - 1, lf, n - 1),
					query(1, 0, n - 1, 0, rg)) << el;
		} else {
			int lf = args[0], rg = args[1], v = args[2];
			if (lf <= rg) update(1, 0, n - 1, lf, rg, v);
			else update(1, 0, n - 1, lf, n - 1, v),
				update(1, 0, n - 1, 0, rg, v);
		}
	}

	return 0;
}
