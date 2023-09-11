#include <bits/stdc++.h>
 
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define ull unsigned long long
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

const int N = 3e5+5;
vector<vector<int>> adjL(N);
bool vis[N];
int cnt;

void dfs(int node)
{
    vis[node] = 1;
    cnt++;
    for(auto child: adjL[node]) if (!vis[child])
        dfs(child);
}

int main()
{
    adhamet
    
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            adjL[i].clear();
        }
        
        for(int i = 0; i < m; i++)
        {
            int u,v;
            cin >> u >> v;
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        
        int mx=0;
        for(int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                cnt = 0;
                dfs(i);
                mx = max(mx, cnt);
            }
        }
        
        cout << mx << el;
    }
}
