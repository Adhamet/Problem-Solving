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
 
int const N = 55;
ll danger=1;
vector<vector<int>> adjL(N);
bool vis[N];
void dfs(int node) {
    vis[node]=true;
    for(auto child: adjL[node]) if (!vis[child]) {
        danger*=2;
        dfs(child);
    }
}
int main()
{
    adhamet;

    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) if ( !vis[i] )
        dfs(i);

    cout << danger;

    return 0;
}
