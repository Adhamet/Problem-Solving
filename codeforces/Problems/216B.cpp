#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

const int N = 100, oo = 1e9+5;
vector<vector<int>> adj;
vector<int> vis;

enum status {PATH=0, CYCLE=1};
status dfs(int node, int parent, int &nodes_cnt)
{
    if(vis[node]) return CYCLE;
    
    vis[node] = 1;
    for(auto child: adj[node]) if(child != parent)
    {
        ++nodes_cnt;    

        if(dfs(child,node,nodes_cnt) == CYCLE) return CYCLE;
    }
    return PATH;
}   

int main()
{
    /* #ifndef ONLINE_JUDGE
	    freopen("test.txt", "rt", stdin);
    #endif */

    adhamet;

    int n,m;
    cin >> n >> m;

    adj = vector<vector<int>>(n);
    vis = vector<int>(n);

    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    

    int benched = 0;
    for(int i = 0; i < n; i++) if(!vis[i])
    {
        int cnt = 0;
        status solution = dfs(i,-1,cnt);

        if(solution == CYCLE)
            benched += (cnt % 2 == 1);
    }

    if( (n-benched) % 2 == 1 ) benched++;
    cout << benched;
    return 0;
}
