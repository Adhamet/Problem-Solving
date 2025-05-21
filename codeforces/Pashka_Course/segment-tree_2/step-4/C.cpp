#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int SHIFT = 500000, MAXN = 1e6 + 10;

struct Node {
	int segs = 0, len = 0, lazycol = -1;
	bool L = false, R = false;
};

vector<Node> t(4*MAXN);

void apply(int v, int tl, int tr, int col) {
	t[v].lazycol = col;
	if (col) {
		t[v].len = tr - tl + 1;
		t[v].L = t[v].R = true;
		t[v].segs = 1;
	} else {
		t[v].len = 0;
		t[v].L = t[v].R = false;
		t[v].segs = 0;
	}
}

void push(int v, int tl, int tr) {
	if (t[v].lazycol == -1) return;
	int tm = (tl + tr) >> 1;
	apply(2*v, tl, tm, t[v].lazycol);
	apply(2*v+1, tm+1, tr, t[v].lazycol);
	t[v].lazycol = -1;
}

Node combine(Node left, Node right) {
	Node res;
	res.len = left.len + right.len;
	res.L = left.L;
	res.R = right.R;
	res.segs = (left.segs + right.segs) - (left.R && right.L);
	return res;
}

void update(int v, int tl, int tr, int l, int r, int col) {
	if (l > r || r < tl || tr < l) return;
	if (tl >= l && tr <= r) {
		apply(v, tl, tr, col);
		return;
	}
	push(v, tl, tr);
	int tm = (tl + tr) >> 1;
	update(2*v, tl, tm, l, r, col);
	update(2*v+1, tm+1, tr, l, r, col);
	t[v] = combine(t[2*v], t[2*v+1]);
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char c;
		int x, l;
		cin >> c >> x >> l;
		x += SHIFT;
		update(1, 0, MAXN-1, x, x+l-1, (c == 'W' ? 0 : 1));
		cout << t[1].segs << ' ' << t[1].len << el;
	}

	return 0;
}

