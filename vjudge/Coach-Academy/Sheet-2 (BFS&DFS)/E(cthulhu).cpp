#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define f first
#define s second
const int N = 1e2+10, oo = 1e9;
vector<int> adj[N];
bool vis[N];
bool cthulhuRules;
int children[N];
void dfs(int node)
{
    for(auto child: adj[node])
    {
        children[node]++;
        if (!vis[child])
        {
            
            vis[child]=1;
            dfs(child);
        }
    }
}
int main()
{
    fff;
    int n, m;
    cin >> n >> m;
    if( !(n == m) )
        return cout << "NO\n",0;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis[1] = 1;
    dfs(1);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if (!vis[i])
            return cout << "NO\n", 0;
        if (children[i] > 1)
            cnt++;
    }   
    if(cnt > 2)
        cout << "FHTAGN!\n";
    return 0;
}