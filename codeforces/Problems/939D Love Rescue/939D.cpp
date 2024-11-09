#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

class DSU {
	private:
		vector<int> par;
		vector<int> sz;
	
	public:
		DSU(int size): par(size), sz(size) {
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

	int n;
	string s, t;
	cin >> n >> s >> t;

	DSU dsu(26);
	vector<pair<char, char>> ans;
	for (int i = 0; i < n; i++) {
		int u = s[i] - 'a', v = t[i] - 'a';
		if (dsu.connected(u, v)) continue;
		dsu.unite(u, v);
		ans.push_back({s[i], t[i]});
	}

	cout << ans.size() << el;
	for (pair<char, char> pr: ans) cout << pr.first << " " << pr.second << el;
	return 0;
}
