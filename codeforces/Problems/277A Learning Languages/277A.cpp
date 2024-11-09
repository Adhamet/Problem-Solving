#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

class DSU {
	private:
		vector<int> par, sz;
	public:
		DSU(int size): par(size), sz(size, 1) {
			for (int i = 0; i < size; i++) par[i] = i;
		}

		int find(int x) { return par[x] == x? x: par[x] = find(par[x]); }
		bool connected(int x, int y) { return find(x) == find(y); }
		void unite(int x, int y) {
			int xRoot = find(x);
			int yRoot = find(y);
			if (xRoot != yRoot) {
				if (sz[xRoot] < sz[yRoot]) swap(xRoot, yRoot);
				sz[xRoot] += sz[yRoot];
				par[yRoot] = xRoot;
			}
		}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	DSU dsu(n);

	bool dis = 1;
	vector<vector<int>> lang(m + 1);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (k > 0) dis = false;
		for (int j = 0; j < k; j++) {
			int l;
			cin >> l;
			lang[l].push_back(i);
		}
	}

	for (int l = 1; l <= m; l++) {
		for (int i = 1; i < lang[l].size(); i++) {
			dsu.unite(lang[l][0], lang[l][i]);
		}
	}

	int components = 0;
	for (int i = 0; i < n; i++) if (dsu.find(i) == i) components += 1;
	if (dis) cout << n << el;
	else cout << components - 1 << el;
	return 0;
}	
