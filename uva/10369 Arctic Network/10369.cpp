#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

struct Point {
	int x, y;
};

struct Edge {
	int u, v;
	double weight;
	bool operator<(const Edge& other) const { return weight < other.weight; }
};

vector<int> par, sz;
void init(int size) {
	par = vector<int>(size), sz = vector<int>(size, 1);
	for (int i = 0; i < size; i++) par[i] = i;
}

int find(int x) { return par[x] == x? x: par[x] = find(par[x]); }
bool unite(int x, int y) {
	int xRoot = find(x), yRoot = find(y);
	if (xRoot == yRoot) return false;
	if (sz[xRoot] < sz[yRoot]) swap(xRoot, yRoot);
	sz[xRoot] += sz[yRoot];
	par[yRoot] = xRoot;
	return true;
}

double calcDist(const Point& p1, const Point& p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int s, p;
		cin >> s >> p;
		vector<Point> pts(p);
		for (int i = 0; i < p; i++) cin >> pts[i].x >> pts[i].y;

		vector<Edge> edges;
		for (int i = 0; i < p; i++) {
			for (int j = i + 1; j < p; j++) {
				double dist = calcDist(pts[i], pts[j]);
				edges.push_back({i, j, dist});
			}
		}

		sort(edges.begin(), edges.end());
		init(p);
		int used = 0;
		double mxW = 0.0;
		for (const auto &edge: edges) {
			if (unite(edge.u, edge.v)) {
				mxW = edge.weight;
				used += 1;
			}

			if (used == p - s) break;
		}

		cout << fixed << setprecision(2) << mxW << el;
	}

	return 0;
}
