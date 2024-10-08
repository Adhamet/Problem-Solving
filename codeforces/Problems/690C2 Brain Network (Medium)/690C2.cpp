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

	vector<bool> vis(n + 1);
	vector<int> adjL[n + 1];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	queue<int> q;
	q.push(1);

	int lastChild;
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		lastChild = node;
		vis[node] = true;
		for (auto child: adjL[node]) {
			if (!vis[child]) q.push(child);
		}
	}
	
	for (int i = 0; i < n + 1; i++) vis[i] = false;
	queue<pi> q2;
	q2.push({lastChild, 0});

	int mxDist = 0;
	while (!q2.empty()) {
		int node = q2.front().first;
		int dist = q2.front().second;
		q2.pop();

		mxDist = max(mxDist, dist);
		vis[node] = true;
		for (auto child: adjL[node]) {
			if (!vis[child]) q2.push({child, dist + 1});
		}
	}

	cout << mxDist << el;
	return 0;
}
