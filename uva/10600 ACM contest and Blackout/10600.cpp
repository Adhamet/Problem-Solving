#include <bits/stdc++.h>
#include <queue>
#include <utility>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

struct Edge {
	int from, to, w, index;
	bool del;
	Edge(int f, int t, int wei, int i) {
		from = f, to = t, w = wei, index = i, del = false;
	}

	bool operator<(const Edge& e) const { return w > e.w; };
	bool operator==(const Edge& e) const {
		return from == e.from && to == e.to && w == e.w;
	}
};

vector<int> par, sz;
void init(int size) {
	par = vector<int>(size), sz = vector<int>(size, 1);
	for (int i = 0; i < size; i++) par[i] = i;
}

int find(int x) { return par[x] == x? x: par[x] = find(par[x]); }
bool unite(int x, int y) {
	int xRoot = find(x);
	int yRoot = find(y);
	if (xRoot == yRoot) return false;

	if (sz[xRoot] < sz[yRoot]) swap(xRoot, yRoot);
	sz[xRoot] += sz[yRoot];
	par[yRoot] = xRoot;
	return true;
}

pair<int, vector<Edge>> prim(int n, vector<Edge>& edges) {
	int minW = 0;
	vector<Edge> ans;
	priority_queue<Edge> pq;

	init(n);
	for (int i = 0; i < edges.size(); i++) {
		if (!edges[i].del) pq.push(edges[i]);
	}

	while (!pq.empty()) {
		Edge curr = pq.top();
		pq.pop();

		if (unite(curr.from, curr.to)) {
			minW += curr.w;
			ans.push_back(curr);
		}
	}

	if (ans.size() != n - 1) return make_pair(INT_MAX, vector<Edge>());
	return make_pair(minW, ans);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		int a, b, w;
		vector<Edge> edges;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> w;
			edges.push_back(Edge(--a, --b, w, i));
		}

		pair<int, vector<Edge>> ans = prim(n, edges);

		int scdMinW = INT_MAX;
		for (int i = 0; i < ans.second.size(); i++) {
			edges[ans.second[i].index].del = true;
			pair<int, vector<Edge>> ansScd = prim(n, edges);
			
			scdMinW = (ansScd.first < scdMinW)? ansScd.first: scdMinW;
			edges[ans.second[i].index].del = false;
		}

		cout << ans.first << " " << scdMinW << el;
	}

	return 0;
}
