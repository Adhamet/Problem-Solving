#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
};

const int N = 1e5 + 5;
/*const int oo = 1e9 + 20;*/
ll component = 0;
bool impossible = false;
vector<pair<int, char>> adj[N];
bool vis[N], color[N];
void dfs(int node, bool col) {
	vis[node] = true;
	color[node] = col;

	for (auto child: adj[node]) {
		if (vis[child.first]) {
			if (child.second == 'S' && color[child.first] != col) impossible = true;
			if (child.second == 'D' && color[child.first] == col) impossible = true;
		} else {
			if (child.second == 'S') dfs(child.first, col);
			else dfs(child.first, !col);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	setIO("revegetate");

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char a;
		int b, c;
		cin >> a >> b >> c;
		adj[b].push_back({c, a});
		adj[c].push_back({b, a});
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) component += 1, dfs(i, 0);
		if (impossible) break;
	}

	if (impossible) cout << 0 << el;
	else {
		cout << 1;
		while (component--) cout << 0;
	}

	return 0;
}
