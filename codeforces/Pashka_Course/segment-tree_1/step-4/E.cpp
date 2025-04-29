#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MAXN = 100005, oo = 1e9+7;
int n;

struct Node {
	int min, max, cnt;
	Node(): cnt(0), min(oo), max(-oo) {};
	Node(int val): cnt(1), min(val), max(val) {};
};

Node t[4*MAXN];

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		if (val == 0) t[v] = Node();
		else t[v] = Node(val);
	} else {
		int tm = (tl + tr) >> 1;
		if (pos <= tm) update(v*2, tl, tm, pos, val);
		else update(v*2+1, tm+1, tr, pos, val);
		t[v].min = min(t[v*2].min, t[v*2+1].min);
		t[v].max = max(t[v*2].max, t[v*2+1].max);
		t[v].cnt = t[v*2].cnt + t[v*2+1].cnt;
	}
}

int query(int v, int tl, int tr, int l, int r, int p) {
	if (r < tl || tr < l || l > r) return 0;
	if (tl >= l && tr <= r) {
		if (t[v].max <= p) {
			int dest = t[v].cnt;
			if (tl == tr) t[v] = Node();
			else {
				int tm = (tl + tr) >> 1;
				int left = query(v*2, tl, tm, l, min(r, tm), p);
				int right = query(v*2+1, tm+1, tr, max(l, tm+1), r, p);
				t[v].min = min(t[v*2].min, t[v*2+1].min);
				t[v].max = max(t[v*2].max, t[v*2+1].max);
				t[v].cnt = t[v*2].cnt + t[v*2+1].cnt;
			}
			return dest;
		} else if (t[v].min > p) return 0;
	}

	int tm = (tl + tr) >> 1;
	int left = query(v*2, tl, tm, l, min(r, tm), p);
	int right = query(v*2+1, tm+1, tr, max(l, tm+1), r, p);
	t[v].min = min(t[v*2].min, t[v*2+1].min);
	t[v].max = max(t[v*2].max, t[v*2+1].max);
	t[v].cnt = t[v*2].cnt + t[v*2+1].cnt;
	return left + right;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m;
	cin >> n >> m;
	for (int i = 0; i < 4*MAXN; ++i) t[i] = Node();
	while (m--) {
		int qry;
		cin >> qry;
		if (qry == 1) {
			int i, h;
			cin >> i >> h;
			update(1, 0, n - 1, i, h);
		} else {
			int l, r, p;
			cin >> l >> r >> p;
			cout << query(1, 0, n - 1, l, r - 1, p) << el;
		}
	}

	return 0;
}
