#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int N=1e2+10;
vector<int> adj[N];
vector<int> res;
bool vis[N];
bool blocked[N];

void dfs(int node)
{
    res.push_back(node);
    for( auto child : adj[node] )
        if(!vis[child])
        {
            vis[child]=1;
            dfs(child);
        }
}

int main()
{
    fff;
    while(true)
    {
        res.clear();
        for(int i = 0; i < N; i++)
        {
            adj[i].clear();
            vis[i]=0;
            blocked[i]=0;
        }
        int n,m;
        cin >> n >> m; 
        if(n+m==0)
            break;

        for(int i = 1; i <= m; i++)
        {   
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            blocked[v] = 1;
        }

        for(int i = 1; i <= n; i++)
            if(!vis[i] && !blocked[i])
            {
                vis[i]=1;
                dfs(i);
            }

        for(auto i : res)
            cout << i << " ";
        cout << endl;
    }
}