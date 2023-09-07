#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define ull unsigned long long
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'

const int N = 100+5;
vector< vector<int> > adjL(N);
bool vis[N];
vector<int> topological_sort;

void dfs(int node) {
    vis[node]=1;
    for(auto child: adjL[node]) if (!vis[child])
        dfs(child);
    topological_sort.push_back(node);
}

int main() 
{/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
    int n,m;
    while(cin >> n >> m)
    {
        topological_sort.clear();
        for(int i = 0; i < N; i++)
        {
            adjL[i].clear();
            vis[i]=0;
        }

        if ( n + m == 0 ) break;

        int u,v;
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v;
            adjL[v].push_back(u);
        }

        for(int i = 1; i <= n; i++) if (!vis[i])
            dfs(i);
        
        for(auto item: topological_sort)
            cout << item << " ";
        cout << el;
    }

	return 0;
}
