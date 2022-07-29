#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int N = 3e4+10;
vector<int> adj[N];
bool vis[N];

void dfs(int node)
{
    vis[node] = true;
    for( auto child : adj[node] )
        if (!vis[child])
            dfs(child);
}

int main()
{
    fff;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    int cnt = 0;
    for(int i = 1; i <= n;i ++)
        if (!vis[i])
        {
            dfs(i);
            cnt++;
        }
     
    return cout << cnt << endl, 0;
}