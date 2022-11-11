#include <bits/stdc++.h>
 
using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define ull unsigned long long
#define F first
#define S second
#define el '\n'

const int N = 210, oo = 1e9+7, MOD=1e9+7;
vector<int> g[N];
int vis[N];

void dfs(int node)
{
    vis[node] = 1;
    for(auto child: g[node])
        if(!vis[child])
            dfs(child);
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        if(m == 0)
        {
            cout << "Not Possible\n";
            continue;
        }

        for(int i = 0; i < n; i++)
            g[i].clear(),vis[i]=0;
        set<int> st;
        for(int i = 0; i < m; i++)
        {
            int u,v;
            cin >> u >> v;
            st.insert(u),st.insert(v);
            g[u].push_back(v),g[v].push_back(u);
        }
        if(!st.empty())
            dfs(*st.begin());
        bool connected = true;
        for(auto j : st)
            if(!vis[j])
                connected = false;
        for(int i = 0 ; i < n ; i++)
            connected &= g[i].size() % 2 == 0;
        
        if(connected)
            cout << "Possible\n";
        else cout << "Not Possible\n";
    }

    return 0;
}