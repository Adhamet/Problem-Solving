#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define fst first
#define scd second
#define el '\n'
#define MOD 1000000007

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int MAXN = 2e5 + 5;
/*const int oo = 1e9 + 20;*/

int dist[2][MAXN];
vector<int> adjL[MAXN];

int dfs(int node, int par, int len, int i) {
	int opt = - 1;
	dist[i][node] = len;

	for (auto child: adjL[node]) if (child != par) {
		int lastOpt = dfs(child, node, len + 1, i);
		if (opt == -1 || dist[i][lastOpt] > dist[i][opt]) opt = lastOpt;
	}

	return opt == -1 ? node: opt;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	int mxNode = dfs(0, 0, 0, 0);
	int mxNode2 = dfs(mxNode, mxNode, 0, 0);
	dfs(mxNode2, mxNode2, 0, 1);
	for (int i = 0; i < n; i++) cout << max(dist[0][i], dist[1][i]) << " ";
	return 0;
}
