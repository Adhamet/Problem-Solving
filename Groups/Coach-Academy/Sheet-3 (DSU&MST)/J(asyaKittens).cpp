#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>
const int N = 15e4+10, oo = 1e9, MOD = 1e9+7;
vector<int> adj[N];
int par[N], cnt[N];
ll sum[N];


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int findparent(int u)
{
    if (par[u] == u)
        return u;
    return findparent(par[u]);
}
void connect(int u, int v)
{
    u = findparent(u);
    v = findparent(v);
    if ( u == v )
        return;
    par[u] = v;
    cnt[v] += cnt[u];
}
bool isConn(int u, int v)
{
    return (findparent(u) == findparent(v));
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


int main()
{
    fff;
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        par[i]=i;
        adj[i].push_back(i);
    }
    
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        u = findparent(u);
        v = findparent(v);
        if ( adj[u].size() > adj[v].size() )
        {
            par[v] = u;
            for(auto j: adj[v])
                adj[u].push_back(j);
        }
        else
        {
            par[u] = v;
            for(auto j: adj[u])
                adj[v].push_back(j);
        }
    }

    for(int i = 1; i <= n; i++)
        if (adj[i].size() == n)
            for(auto j : adj[i])
                cout << j << " ";
}