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

const int N = 1e5+5;
map<int, vector<int>> adjL;
map<int, bool> vis;
vector<int> path;

void dfs(int node) {
    vis[node] = true;
    for(auto child: adjL[node]) if (!vis[child])
        dfs(child);
    path.push_back(node);
}

int main()
{
    adhamet;

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    for(auto it: adjL) if (it.second.size() == 1) {
        dfs(it.first);
        break;
    }

    for(auto it: path) cout << it << " ";
    return 0;
}
