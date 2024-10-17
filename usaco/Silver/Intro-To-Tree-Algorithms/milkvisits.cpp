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
void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

const int MAXN = 1e5 + 5;
int currComp;
bool vis[MAXN];
vector<int> adjL[MAXN], farm(MAXN), comp(MAXN);

void dfs(int node) {
	if (vis[node]) return;
	
	vis[node] = true;
	comp[node] = currComp;
	for (auto child: adjL[node]) if (farm[node] == farm[child]) {
		dfs(child);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	setIO("milkvisits");	
	int n, m;
	string cows;
	cin >> n >> m >> cows;
	for (int i = 0; i < n; i++) {
		farm[i] = (cows[i] == 'H');
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	currComp = 1;
	for (int i = 0; i < n; i++) if (!comp[i]) {
		dfs(i), currComp += 1;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;

		int type = (c == 'H');
		--a, --b;

		if (comp[a] != comp[b] || farm[a] == type) cout << 1;
		else cout << 0;
	}
	
	cout << el;
	return 0;
}
