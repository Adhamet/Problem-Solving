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

const int N = 1e6+5;
vector<vector<int>> adjL(N);
bool vis[N];
bool cyclic=false;
vector<int> topoSt(N);
void dfs(int node, int parent)
{
    vis[node] = true;
    for(auto child : adjL[node]) if(!vis[child])
            dfs(child, node);
    else cyclic = true;
    topoSt.push_back(node);
}

int main()
{
    int n,m;
    while (cin >> n >> m)
    {
        if (n + m == 0) break;

        topoSt.clear();
        cyclic = false;
        for(int i = 1; i <= n; i++)
        {
            adjL[i].clear();
            vis[i]=0;
        }

        for(int i = 0; i < m; i++)
        {
            int u,v;
            cin >> u >> v;
            adjL[u].push_back(v);
        }

        for(int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i,0);
            if (cyclic) break;
        }

        if (cyclic) cout << "IMPOSSIBLE\n";
        else for(auto it = topoSt.rbegin(); it != topoSt.rend(); it++)
            cout << *it << el;
    }
}
