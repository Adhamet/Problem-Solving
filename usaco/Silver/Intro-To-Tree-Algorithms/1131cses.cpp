#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
// void setIO(string name = "") {
// 	if (name.size()) {
// 		freopen((name+".in").c_str(), "r", stdin);
// 		freopen((name+".out").c_str(), "w", stdout);
// 	}
// }

const int MAXN = 2e5 + 5;
bool vis[MAXN];
vector<int> adjL[MAXN];

pi dfs(int node, int dist) {
    vis[node] = true;
    pi farthest = {dist, node};

    for (auto child: adjL[node]) if (!vis[child]) {
        auto candidate = dfs(child, dist + 1);
        if (candidate.first > farthest.first) farthest = candidate;
    }

    return farthest;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// setIO("pails");
	
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	memset(vis, 0, sizeof(vis));
  pi feedback = dfs(1, 0);
  memset(vis, 0, sizeof(vis));
  feedback = dfs(feedback.second, 0);
	
	cout << feedback.first << el;
	return 0;
}
