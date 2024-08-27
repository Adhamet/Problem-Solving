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
vector<vector<int>> adjL;
vector<int> vis, init, goal, flipped;

void dfs(int node, bool prop, bool prevProp) {
    if (vis[node]) return;
    vis[node] = 1;
    bool diff = (init[node] != goal[node]);
    if (prevProp^diff) flipped.push_back(node);
    for(auto child : adjL[node])
        dfs(child, diff, prop);
}

int main()
{
    adhamet;

    int n;
    cin >> n;
    adjL = vector<vector<int>>(n+2);
    vis = vector<int>(n+2);
    init = vector<int>(n+2);
    goal = vector<int>(n+2);

    for(int i = 0; i < n-1; i++) {
        int u,v;
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
        cin >> init[i];
    for(int i = 1; i <= n; i++)
        cin >> goal[i];

    dfs(1,0,0);
    cout << flipped.size() << el;
    for(auto it: flipped)
        cout << it << el;

    return 0;
}
