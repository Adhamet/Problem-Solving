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

/*const int MAXN = 20 + 5;*/
/*const int oo = 1e9 + 20;*/
void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int Th, ans;
vector<bool> vis;
vector<vector<pair<int, int>>> adjL;

void dfs(int node) {
	vis[node] = true;
	for (auto child: adjL[node]) {
		if (!vis[child.first] && child.second >= Th) {
			ans += 1, dfs(child.first);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	setIO("mootube");
	int n, q;
	cin >> n >> q;
	adjL.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v, rel;
		cin >> u >> v >> rel;
		--u, --v;
		adjL[u].push_back({v, rel});
		adjL[v].push_back({u, rel});
	}

	while (q--) {
		int start;
		cin >> Th >> start;
		--start;

		ans = 0;
		vis = vector<bool>(n);
		dfs(start);
		cout << ans << el;
	}

	return 0;
}
