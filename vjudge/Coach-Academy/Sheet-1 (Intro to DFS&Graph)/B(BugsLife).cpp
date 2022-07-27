#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int N = 2e4+10;
// Adjacency list will be used:
vector<int> adj[N];
int colors[N];
bool sus = false;

// Checking for color differences in DFS
void dfs(int node, int color)
{
    colors[node] = color;
        
    for( auto child : adj[node] )
    {
        int next = !color;  
        if (colors[child] == -1)
            dfs(child, next);
        else if (colors[child] != next)
            sus = true;
    }
}

int main()
{
    fff;
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int n,m;
        cin >> n >> m;

         // Initializing
        sus = false;
        for(int j=1; j<=n; j++)
        {
            colors[j] = -1;
            adj[j].clear();
        }

        // Standard Adjacent List input-taking
        for(int j = 0; j < m; j++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int j = 1; j <= n; j++)
            if(colors[j] == -1)
                dfs(j, 0);

        cout << "Scenario #" << i << ":\n";
        sus ? cout << "Suspicious bugs found!\n" : cout << "No suspicious bugs found!\n";
    }
    return 0;
}