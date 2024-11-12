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

	int n, m;
	cin >> n >> m;
	init(2e5+5);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		unite(u, v);
	}

	int ans = 0;
	for (int i = 0; i < n;) {
		int par = find(i);
		for (int j = i + 1; j <= par; j++) {
			if (find(i) != find(j)) {
				ans += 1;
				unite(i, j);
			}

			par = max(par, find(j));
		}

		i = par + 1;
	}

	cout << ans << el;
	return 0;
}
