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
const int N = 1e5+5/*, oo = 1e9+7, mod = 1e9+7*/;

vi vis(N);
vector<vi> adjL(N);
map<int, pair<int,int>> idx;
void dfs(int node, vector<pi>& pts) {
	if(vis[node]) return;
	pts.push_back(idx[node]);
	vis[node] = true;
	for(auto child: adjL[node])
		dfs(child,pts);
}

int main()	{
	freopen("fenceplan.in","r",stdin);
	freopen("fenceplan.out","w",stdout);
	adhamet;
	int n,m;	cin >> n >> m;
	
	vi x(n),y(n),power(n);	
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		idx[i+1] = make_pair(x[i],y[i]);
	}
	
	for(int i = 0; i < m; i++) {
		int u,v;	cin >> u >> v;
		adjL[u].push_back(v);
		adjL[v].push_back(u);
	}

	ll minPerm = LLONG_MAX;
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vector<pi> pts;
			dfs(i, pts);
			int minX = INT_MAX, maxX = INT_MIN;
			int minY = INT_MAX, maxY = INT_MIN;
			for (auto& p : pts) {
				minX = min(minX, p.F);
				maxX = max(maxX, p.F);
				minY = min(minY, p.S);
				maxY = max(maxY, p.S);
			}
			minPerm = min(minPerm, 2LL * (maxX - minX + maxY - minY));
		}
	}
	cout << minPerm;
	return 0;
}

