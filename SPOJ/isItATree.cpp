// SPOJ
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
const int N = 1e4+10, oo = 1e9+2; 
vector<int> adj[N];
bool vis[N];

void dfs(int node)
{
    vis[node] = 1;
    for(auto child: adj[node])
        if(!vis[child])
            dfs(child);
}

// Check connectivity
bool vis2[N];
bool notCyclic = false;
void dfs2(int node, int parent)
{
    vis2[node] = 1;
    for(auto child: adj[node])
    {
        if(!vis2[child])
            dfs2(child, node);
        else if(child != parent)
            notCyclic = true;
    }
}
 
int main()
{
    adhamet;
 
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            return cout << "NO\n",0;
    dfs2(1,0);
    if(!notCyclic)
        cout << "YES\n";
    else cout << "NO\n";
}