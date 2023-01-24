#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int N = 1e5+10;
// Adjacency list will be used:
map<int, vector<int>> adj;
vector<int> path;
map<int, bool> vis;

void dfs(int node)
{
    path.push_back(node);
    vis[node] = true;
    for(auto child : adj[node])
        if(!vis[child])
            dfs(child);
}   

int main()
{   
    int n;
    cin >> n;   
    for(int i = 0; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(auto i:adj)
    {
        if(i.second.size()==1)
        {
            dfs(i.first);
            break;
        }
    }
    
    reverse(path.begin(),path.end());

    for(int i : path) cout << i << " ";
    cout << endl;
    return 0;
}
