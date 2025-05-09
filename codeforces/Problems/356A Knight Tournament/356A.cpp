#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 3e5 + 5;
int n;

struct Node {
	int val = 0;
	bool lazy = false;
};

Node t[4 * MAXN];

void apply(int v, int w) {
	if (t[v].val == 0) {
		t[v].val = w;
		t[v].lazy = true;
	}
}

void push(int v) {
	if (!t[v].lazy) return;
	apply(v*2, t[v].val);
	apply(v*2+1, t[v].val);
	t[v].lazy = false;
}

void update(int v, int tl, int tr, int l, int r, int w) {
	if (l > r || r < tl || tr < l || t[v].val != 0) return;
	if (tl >= l && tr <= r) apply(v, w);
	else {
		push(v);
		int tm = (tl + tr) >> 1;
		update(v*2, tl, tm, l, r, w);
		update(v*2+1, tm+1, tr, l, r, w);
	}
}

vector<int> ans;
void query(int v, int tl, int tr) {
	if (tl == tr) {
		ans[tl] = t[v].val;
		return;
	}
	push(v);
	int tm = (tl + tr) >> 1;
	query(v*2, tl, tm);
	query(v*2+1, tm+1, tr);
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	int m;
	cin >> n >> m;
	ans.assign(n + 1, 0);

	while (m--) {
		int l, r, w;
		cin >> l >> r >> w;
		if (l < w) update(1, 1, n, l, w - 1, w);
		if (w < r) update(1, 1, n, w + 1, r, w);
	}

	query(1, 1, n);
	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
	return 0;
}

