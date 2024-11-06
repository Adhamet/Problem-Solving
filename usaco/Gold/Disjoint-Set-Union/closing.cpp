#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'
void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

class DSU {
	private:
		vector<int> par;
		vector<int> sz;

	public:
		DSU(int size): par(size), sz(size, 1) {
			iota(par.begin(), par.end(), 0);
		}

		int find(int x) { return par[x] == x? x: par[x] = find(par[x]); }
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
	setIO("closing");

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> closingOrder(n);
	for (int i = 0; i < n; i++) {
		cin >> closingOrder[i];
		--closingOrder[i];
	}

	DSU dsu(n);
	int components = 0;
	vector<string> result(n);
	vector<bool> isActive(n, false);
	for (int i = n - 1; i >= 0; i--) {
		int barn = closingOrder[i];
		isActive[barn] = true;
		components += 1;

		for (int neigh: adj[barn]) if (isActive[neigh]) {
			if (dsu.find(barn) != dsu.find(neigh)) {
				dsu.unite(barn, neigh);
				components -= 1;
			}
		}

		result[i] = (components == 1) ? "YES": "NO";
	}

	for (auto str: result) cout << str << el;
	return 0;
}
