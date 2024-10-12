#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 100005;
/*const int oo = 1e9 + 20;*/
vector<int> adjL[N + 1];
ll r = 0, b = 0;
void dfs(int node, int par, bool col) {
	(col ? b: r) += 1;
	for (int child: adjL[node]) if (child != par) {
		dfs(child, node, !col);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}
	dfs(1, 0, 0);
	cout << b * r - (n - 1) << el;
	return 0;
}
