#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

vector<int> par, sz;
void init(int size) {
	par = vector<int>(size);
	sz = vector<int>(size, 1);
	for (int i = 0; i < size; i++) par[i] = i;
}

int find(int x) { return par[x] == x? x: par[x] = find(par[x]); }
void unite(int x, int y) {
	int xRoot = find(x);
	int yRoot = find(y);
	if (xRoot != yRoot) {
		if (sz[xRoot] < sz[yRoot]) swap(xRoot, yRoot);
		sz[xRoot] += sz[yRoot], par[yRoot] = xRoot;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n; 
		cin >> n;
		init(n);

		set<tuple<ll, int, int>> e;
		for (int u = 0; u < n; u++) {
			string trash;	cin >> trash;

			int neighs;
			cin >> neighs;
			while (neighs--) {
				ll w;
				int v;
				cin >> v >> w;
				e.insert({w, min(u, --v), max(u, v)});
			}
		}

		ll minW = 0;
		for (const auto& [w, u, v]: e) {
			if (find(u) != find(v)) {
				minW += w;
				unite(u, v);
			}
		}

		cout << minW << el;
	}

	return 0;
}
