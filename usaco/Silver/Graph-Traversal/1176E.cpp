#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> adjL(n + 1);
		vector<int> color(n + 1, -1);

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;

			adjL[u].push_back(v);
			adjL[v].push_back(u);
		}

		queue<int> q;
		q.push(1);
		color[1] = 0;

		vector<int> zeros, ones;
		while (!q.empty()) {
			int node = q.front();
			q.pop();

			if (color[node] == 0) zeros.push_back(node);
			else ones.push_back(node);

			for (int child: adjL[node]) {
				if (color[child] == -1) {
					color[child] = 1 - color[node];
					q.push(child);
				}
			}
		}

		if (zeros.size() <= ones.size()) {
			cout << zeros.size() << el;
			for (auto vertex: zeros) cout << vertex << " ";
		} else {
			cout << ones.size() << el;
			for (auto vertex: ones) cout << vertex << " ";
		}

		cout << el;
	}

	return 0;
}
