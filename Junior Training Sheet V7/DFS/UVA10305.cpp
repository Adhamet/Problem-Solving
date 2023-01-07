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
vector<int> result;
bool vis[N];

void dfs(int node)
{
    vis[node] = 1;
    for(auto child: adj[node])
        if(!vis[child])
            dfs(child);
    result.push_back(node);
}
 
int main()
{
    adhamet;
    
    while(true)
    {
        result.clear();
        for(int i = 0; i < N; i++)
        {
            adj[i].clear();
            vis[i]=0;
        }

        int n,m,u,v;
        cin >> n >> m;
        if(n+m==0) break;

        for(int i = 0; i < m; i++)
        {
            cin >> u >> v;
            adj[v].push_back(u);
        }
        dfs(1);
        for(int i = 2; i <= n; i++)
            if(!vis[i])
                dfs(i);
        
        for(auto item : result)
            cout << item << " ";
        cout << el;
    }

    return 0;
}