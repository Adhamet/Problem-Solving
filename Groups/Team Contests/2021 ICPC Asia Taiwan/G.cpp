#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

const int N = 2e5+5;
vector<pair<int,int>> grid[N];
int vis[N][N];
ll ans;

void dfs(int node, int par, int length=1) {
	vis[node][par] = true;
	if(length >= 2) ans++;
	for(auto ch: grid[node]) {
		if(!vis[node][par] && grid[node].second < ch.second) {
			dfs(ch.first,node);	
		}
	}
}

int main()
{
    adhamet;

    int n;	cin >> n;
    for(int i = 1; i <= n-1; i++) {
    	int u,v,w;	cin >> u >> v >> w;
    	grid[u].push_back(make_pair(v,w));
    	grid[v].push_back(make_pair(u,w));
    }

    ans = (n-1)*2;
    for(auto itr = grid.begin(); itr!=grid.end(); itr++) {
    	dfs(itr->first, itr-itr.begin());
    }
    cout << ans;
	
    return 0;
}