#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'
 
struct DSU {
	vector<int> par, sz;
	int compCnt, mxSz;
 
	DSU(int size): par(size), sz(size, 1), compCnt(size), mxSz(1) {
		for (int i = 0; i < size; i++) par[i] = i;
	}
 
	int find(int x) { return par[x] == x? x: par[x] = find(par[x]); }
	bool connected(int x, int y) { return find(x) == find(y); }
	bool unite(int x, int y) {
		int X = find(x);
		int Y = find(y);
		if (X == Y) return false;

		if (sz[X] < sz[Y]) swap(X, Y);
		sz[X] += sz[Y];
		par[Y] = X;

		compCnt -= 1;
		mxSz = max(mxSz, sz[X]);
		return true;
	}
 
	int getCC() const { return compCnt; }
	int getMS() const { return mxSz; }
};
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
 
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		dsu.unite(--u, --v);
		cout << dsu.getCC() << " " << dsu.getMS() << el;
	}
 
	return 0;
}
