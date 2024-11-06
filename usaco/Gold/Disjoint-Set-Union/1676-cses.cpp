#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

class DSU {
	private:
		vector<int> pars;
		vector<int> szs;
		int componentCnt;
		int mxSize;

	public:
		DSU(int size): pars(size), szs(size, 1), componentCnt(size), mxSize(1) {
			for (int i = 0; i < size; i++) pars[i] = i;
		}

		int find(int x) { return pars[x] == x? x: pars[x] = find(pars[x]); }
		bool connected(int x, int y) { return find(x) == find(y); }
		bool unite(int x, int y) {
			int xRoot = find(x);
			int yRoot = find(y);
			if (xRoot == yRoot) return false;

			if (szs[xRoot] < szs[yRoot]) swap(xRoot, yRoot);
			szs[xRoot] += szs[yRoot];
			pars[yRoot] = xRoot;

			componentCnt -= 1;
			mxSize = max(mxSize, szs[xRoot]);
			return true;
		}

		int getComponentCnt() const { return componentCnt; }
		int getMaxSize() const { return mxSize; }
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
		cout << dsu.getComponentCnt() << " " << dsu.getMaxSize() << el;
	}

	return 0;
}
