#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

class DSU {
	private:
		vector<int> pars;
		vector<int> sizes;

	public:
		DSU(int size): pars(size), sizes(size, 2) {
			for (int i = 1; i < size; i++) pars[i] = i;
		}

		int find(int x) { return pars[x] == x? x: pars[x] = find(pars[x]); }
		bool connected(int x, int y) { return find(x) == find(y); }
		bool unite(int x, int y) {
			int xRoot = find(x);
			int yRoot = find(y);
			if (xRoot == yRoot) return false;

			if (sizes[xRoot] < sizes[yRoot]) swap(xRoot, yRoot);
			sizes[xRoot] += sizes[yRoot];
			pars[yRoot] = xRoot;
			return true;
		}
};

int main() {
	ios_base::sync_with_stdio(1), cin.tie(0);

	int n, q;
	cin >> n >> q;
	DSU dsu(n);
	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 0) dsu.unite(u, v);
		else cout << dsu.connected(u, v) << el;
	}

	return 0;
}
