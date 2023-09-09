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

const int N = 2e4+10;
vector<vector<int>> adjL(N);
int colors[N];
bool cyclic = false;
void dfs(int node, int color) {
    colors[node] = color;

    for(auto child: adjL[node]) {
        int next = !color;
        if (colors[child] == -1) dfs(child,next);
        else if (colors[child] != next) cyclic = true;
    }
}
int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int n,m;
        cin >> n >> m;

        cyclic = false;
        for(int j = 1; j <= n; j++)
        {
            adjL[j].clear();
            colors[j] = -1;
        }

        for(int j = 0; j < m; j++) {
            int u,v;
            cin >> u >> v;
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }

        for(int j = 1; j <= n; j++) if (colors[j] == -1) {
            dfs(j,0);
            if ( cyclic ) break;
        }

        cout << "Scenario #" << i << ":\n";
        if ( cyclic )
            cout << "Suspicious bugs found!" << el;
        else cout << "No suspicious bugs found!" << el;
    }
}
