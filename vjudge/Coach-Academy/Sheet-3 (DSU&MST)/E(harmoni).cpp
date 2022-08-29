#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>

const int N = 2e5+10, oo = 1e9;
vector<int> adj[N];
int par[N],mn,mx;
bool vis[N];

void dfs(int node)
{
    mn = min(mn, node);
    mx = max(mx, node);
    for(auto j: adj[node])
    {
        if(!vis[j])
        {
            vis[j] = 1;
            dfs(j);
        }
    }
}

int main()
{
    fff;
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    int result = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            mn = oo;
            mx = 0;
            vis[i] = 1;
            dfs(i);
            for(int j = mn; j<=mx; j++)
                if(!vis[j])
                {
                    result++;
                    dfs(j);
                }
        }
    }
    cout << result << '\n';
}