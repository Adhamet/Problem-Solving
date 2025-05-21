#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const i32 MAXN = 1e9;
const i64 oo = 1e18;
struct Node {
	int tl, tr;
	i64 sum, lazyset;
	Node *left, *right;
	
	Node(int l, int r): tl(l), tr(r), sum(0), lazyset(oo), left(nullptr), right(nullptr) {}

	void push() {
		if (lazyset == oo) return;
		if (tl != tr) {
			int tm = (tl + tr) >> 1;
			if (!left) left = new Node(tl, tm);
			if (!right) right = new Node(tm + 1, tr);
			left->apply(lazyset);
			right->apply(lazyset);
		}
			
		lazyset = oo;
	}

	void apply(i64 val) {
		sum = (tr - tl + 1) * val;
		lazyset = val;
	}

	void update(int l, int r, i64 val) {
		if (l > r || tr < l || tl > r) return;
		if (tl >= l && tr <= r) apply(val);
		else {
			push();
			int tm = (tl + tr) >> 1;
			if (!left) left = new Node(tl, tm);
			if (!right) right = new Node(tm + 1, tr);
			left->update(l, r, val);
			right->update(l, r, val);
			sum = left->sum + right->sum;
		}
	}

	i64 query(int pos) {
		if (pos < tl) return 0;
		if (pos >= tl && pos <= tr) return sum;
		push();
		i64 res = 0;
		if (left) res += left->query(pos);
		if (right) res += left->query(pos);
		return res;
	}

	int findLast(i64 h, i64 curr = 0) {
		if (curr > h) return tl - 1;
		if (tl == tr) return (curr + sum <= h? tr: tl - 1);
		push();
		i64 leftSum = left? left->sum: 0;
		if (curr + leftSum > h)
			return left? left->findLast(h, curr): tl - 1;
		else {
			int rightGo = right? right->findLast(h, curr+leftSum): tr;
			return rightGo;
		}
	}
};

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	Node *root = new Node(1, n);

	string cmd;
	while (cin >> cmd && cmd != "E") {
		if (cmd == "I") {
			int a, b, d; cin >> a >> b >> d;
			root->update(a, b, d);
		} else if (cmd == "Q") {
			int h; cin >> h;
			cout << root->findLast(h) << el;
		}
	}

	return 0;
}
