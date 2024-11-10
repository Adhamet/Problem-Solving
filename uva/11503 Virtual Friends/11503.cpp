#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define fst first
#define scd second
#define el '\n'

vector<int> par, sz;
void init(int size) {
	par = vector<int>(size), sz = vector<int>(size, 1);
	for (int i = 0; i < size; i++) par[i] = i;
}

int find(int x) { return par[x] == x? x: par[x] = find(par[x]); }
int getComponentSz(int x) { return sz[find(x)]; }
void unite(int x, int y) {
	int xRoot = find(x), yRoot = find(y);
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
		int m, idx = 0;
		cin >> m;
		unordered_map<string, int> mp;
		init(2 * m);
		for (int i = 0; i < m; i++) {
			string s, t;
			cin >> s >> t;
			if (mp.find(s) == mp.end()) mp[s] = idx++;
			if (mp.find(t) == mp.end()) mp[t] = idx++;
			int u = mp[s], v = mp[t];
			unite(u, v);
			cout << getComponentSz(u) << el;
		}
	}

	return 0;
}
