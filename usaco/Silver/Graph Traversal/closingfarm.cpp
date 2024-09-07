#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
const int N = 3005/*, oo = 1e9+7, mod = 1e9+7*/;

vector<vi> adjL(N);
int vis[N], closed[N], nodes=0;
void dfs(int node) {
	if(vis[node] || closed[node]) return;

	nodes++;
	vis[node] = true;
	for(auto child: adjL[node]) dfs(child);
}

int main()	{
	freopen("closing.in","r",stdin);
	freopen("closing.out","w",stdout);
	adhamet;

	int n, m;	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u,v;	cin >> u >> v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	vi q(n);	for(auto &i: q) cin >> i;
	dfs(1);
	if(nodes == n) cout << "YES\n";
	else cout << "NO\n";

	for(int i = 0; i < n-1; i++) {
		nodes = 0;
		closed[q[i]] = true;
		fill(vis,vis+n+3,false);
		dfs(q[n-1]);
		if(nodes == n-i-1) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}

