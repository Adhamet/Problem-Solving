#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
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
		void unite(int x, int y) {
			int xRoot = find(x), yRoot = find(y);
			if (xRoot != yRoot) {
				if (sz[xRoot] < sz[yRoot]) swap(xRoot, yRoot);
				sz[xRoot] += sz[yRoot];
				par[yRoot] = xRoot;
			}
		}
};

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	

	return 0;
}
