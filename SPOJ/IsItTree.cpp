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

const int N = 1e4+10;
vector< vector<int> > adjL(N);
bool vis[N];

bool cyclic = false;
void dfs(int node, int parent) {
    vis[node] = 1;
    for(auto child: adjL[node]) if (!vis[child])
        dfs(child,node);
    else if (child != parent) cyclic = true;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    dfs(1,0);
    for(int i = 1; i <= n; i++) if (!vis[i])
        return cout << "NO\n",0;
    
    if ( cyclic )
        return cout << "NO\n",0;
    return cout << "YES\n",0;
}
