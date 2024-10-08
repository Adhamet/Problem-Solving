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

	int n, m;
	cin >> n >> m;
	if (n != m) {
		cout << "NO" << el;
		return 0;
	}

	vector<int> adjL[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	queue<pi> q;
	vector<bool> vis(n + 1, false);
	
	q.push({1, 0});
	vis[1] = true;

	int connNodes = 0;
	bool cyclic = false;
	while (!q.empty()) {
		int node = q.front().first;
		int par = q.front().second;
		q.pop();

		connNodes += 1;

		for (auto child: adjL[node]) {
			if (!vis[child]) vis[child] = true, q.push({child, node});
			else if (child != par) cyclic = true;
		}
	}

	cout << (cyclic && connNodes == n? "FHTAGN!": "NO") << el;
	return 0;
}
