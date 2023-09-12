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

const int N = 1000000+5;
vector<vector<int>> adjL(N);
bool vis[N];
int res[N];

void dfs(int node, int par) {
    for(auto child: adjL[node]) if (!vis[child]) {
        vis[child]=1;
        dfs(child,node);
    }
    res[node] = par;
}

int main()
{
    adhamet;

    int n,r1,r2;
    cin >> n >> r1 >> r2;
    for(int i = 1; i <= n; i++)
    {
        if (i == r1) continue;
        int u;
        cin >> u;
        adjL[i].push_back(u);
        adjL[u].push_back(i);
    }
    dfs(r2,r2);
    for(int i = 1; i <= n; i++) if (i != r2)
        cout << res[i] << " ";

    return 0;
}
