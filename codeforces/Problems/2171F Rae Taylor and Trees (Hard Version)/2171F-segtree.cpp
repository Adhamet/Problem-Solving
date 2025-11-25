#include <bits/stdc++.h>

using i64 = long long;

struct SegTreeMin {
	std::vector<int> tree, a;

	SegTreeMin(int n, std::vector<int>& in): tree((4*n)+1), a(in) {};

	void build(int v, int tl, int tr) {
		if (tl == tr) tree[v] = a[tl];
		else {
			int tm = (tl + tr) >> 1;
			build(v<<1, tl, tm);
			build(v<<1|1, tm+1, tr);
			tree[v] = std::min(tree[v<<1], tree[v<<1|1]);
		}
	}

	void update(int v, int tl, int tr, int idx, int nVal) {
		if (tl == tr) tree[v] = nVal;
		else {
			int tm = (tl + tr) >> 1;
			if (idx <= tm) update(v<<1, tl, tm, idx, nVal);
			else update(v<<1|1, tm + 1, tr, idx, nVal);
			tree[v] = std::min(tree[v<<1], tree[v<<1|1]);
		}
	}

	int query(int v, int tl, int tr, int l, int r) {
		if (l > r) return INT_MAX;
		if (tl >= l && tr <= r) return tree[v];
		int tm = (tl + tr) >> 1;
		int lft = query(v<<1, tl, tm, l, std::min(r, tm)); // go left
		int rht = query(v<<1|1, tm+1, tr, std::max(l, tm+1), r); // go right
		return std::min(lft, rht);
	}
};


void solve() {
	int n;	std::cin >> n;
	std::vector<int> p(n), pn(n);
	std::vector<int> pos(n+1);
	for (int i = 0; i < n; ++i) std::cin >> p[i], pn[i] = -p[i], pos[p[i]] = i;

	SegTreeMin stMn(n, p), stMx(n, pn);
	stMn.build(1, 0, n-1);
	stMx.build(1, 0, n-1);

	std::vector<std::pair<int,int>> edges;
	std::queue<int> q;

	q.push(p[0]);
	stMn.update(1, 0, n-1, pos[0], INT_MAX);
	stMx.update(1, 0, n-1, pos[0], 0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		while (stMn.query(1, 0, n-1, 0, pos[u]) < u) {
			int v = stMn.query(1, 0, n-1, 0, pos[u]);
			edges.push_back({v, u});
			stMn.update(1, 0, n-1, pos[v], INT_MAX);
			stMx.update(1, 0, n-1, pos[v], 0);
			q.push(v);
		}
		while (-stMx.query(1, 0, n-1, pos[u], n-1) > u) {
			int v = -stMx.query(1, 0, n-1, pos[u], n-1);
			edges.push_back({u, v});
			stMn.update(1, 0, n-1, pos[v], INT_MAX);
			stMx.update(1, 0, n-1, pos[v], 0);
			q.push(v);
		}
	}

	if ((int)edges.size() != n - 1) std::cout << "No\n";
	else {
		std::cout << "Yes\n";
		for (auto &[u,v]: edges) std::cout << u << ' ' << v << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;	std::cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
