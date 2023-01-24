#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int N = 3e4+10;
// Adjancency list:
vector<int> adj[N];
bool vis[N];
int cnt;
void dfs(int node)
{
    vis[node]=1;
    cnt++;
    for( auto child : adj[node] )
        if(!vis[child])
            dfs(child);
}

int main()
{
    fff;
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i = 0; i < m ; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int maxim=0;
        for(int i = 1; i<=n ; i++)
        {
            if (!vis[i])
            {
                cnt=0;
                dfs(i);
                maxim=max(maxim,cnt);
            }
        }
        cout << maxim << endl;

        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
            vis[i]=0;       
        }
    }
}