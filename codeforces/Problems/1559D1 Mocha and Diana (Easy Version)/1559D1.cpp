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
		void unite(int x, int y) {
			int xRoot = find(x);
			int yRoot = find(y);
			if (xRoot != yRoot) {
				if (sz[xRoot] < sz[yRoot]) swap(xRoot, yRoot);
				sz[xRoot] += sz[yRoot], par[yRoot] = xRoot;
			}
		}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m, d;
	cin >> n >> m >> d;
	DSU f(n), s(n);

	int fedges = 0;
	while (m--) {
		int u, v;
		cin >> u >> v;
		f.unite(--u, --v);
		fedges += 1;
	}

	int sedges = 0;
	while (d--) {
		int u, v;
		cin >> u >> v;
		s.unite(--u, --v);
		sedges += 1;
	}

	bool acc = true;
	vector<pair<int, int>> ans;
	int mnEdges = min(fedges, sedges);
	for (int i = 0; i < n && mnEdges < n - 1; i++) {
		for (int j = i + 1; j < n && mnEdges < n - 1; j++) {
			if (f.find(i) != f.find(j) && s.find(i) != s.find(j)) {
				f.unite(i, j);
				s.unite(i, j);
				ans.emplace_back(i + 1, j + 1);
				mnEdges += 1;
			}
		}
	}

	cout << ans.size() << el;
	for (auto pr: ans) cout << pr.first << " " << pr.second << el;
	return 0;
}
