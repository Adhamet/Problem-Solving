#include <bits/stdc++.h>
#include <iomanip>
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
double ans;
vector<bool> vis;
vector<vector<int>> adjL;

void dfs(int node, int currLen, double currProb) {
	vis[node] = true;
	int moves = 0;
	for (auto child: adjL[node]) if (!vis[child]) {
		moves += 1;
	}

	if (!moves) ans += currLen * currProb;
	else {
		double newProb = currProb / moves;
		for (auto child: adjL[node]) if (!vis[child]) {
			dfs(child, currLen + 1, newProb);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vis.resize(n + 1);
	adjL.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adjL[a].push_back(b);
		adjL[b].push_back(a);
	}

	dfs(1, 0, 1);
	cout << setprecision(10) << ans << el;
	return 0;
}
