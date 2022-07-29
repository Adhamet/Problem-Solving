#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio, cin.tie(0), cout.tie(0);
const int N = 2e3+10;
int group;
vector<int> adj[N];
bool vis[N];
int maxLevel;
void dfs(int node, int level)
{
    maxLevel = max(maxLevel, level);
    for(auto child : adj[node])
        if ( !vis[child] )
        {
            vis[child]=1;
            dfs(child, level+1);
        }
}

int main()
{
    fff;
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        if ( p == -1 )
            v.push_back(i);
        else
            adj[p].push_back(i);
    }
    for(auto i: v)
        dfs(i,1);
    cout << maxLevel << endl;
}