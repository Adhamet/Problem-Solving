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

const int N = 10e6+5, oo = 1e9+7;
vector<int> adj[N];
bool vis[N];
int n,m;


int main()
{
    //adhamet;
    int n,m;
    while(true)
    {
        cin >> n >> m;
        if (!n && !m) break;
        vector<ll> indeg(n+1, 0);
        for(auto i: adj) i.clear();

        for(int i = 0; i < m; i++) {
            ll u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            indeg[v]++;
        }
    
        priority_queue<ll> q;
        vector<ll> result;

        for(int i = 0; i <= n; i++){
            if(!indeg[i])
                q.push(-i);
        }

        while(q.size())
        { 
            ll u = -q.top();
            q.pop();
            result.push_back(u);
            for(auto child: adj[u])
            {
                if(!(--indeg[child]))
                    q.push(-child);
            }
        }
        if(result.size() != n) cout << "IMPOSSIBLE" << endl;
        else for(auto i = result.rbegin(); i != result.rend(); i++) cout << *i << endl;
    }
}
