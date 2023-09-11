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
 
const int N = 5005;
vector<vector<int>> adjL;
vector<bool> vis;
map<string,int> mp;
int cnt;

void dfs(int node)
{
    vis[node]=1;
    cnt++;
    for(auto child: adjL[node]) if (!vis[child])
        dfs(child);
}

int main()
{
    adhamet;

    int C,R;

    while(cin >> C >> R)
    {
        if (!C) break;

        adjL = vector<vector<int>>(C+2);
        vis = vector<bool>(C+2);
        mp.clear();

        for(int i = 1; i <= C; i++) {
            string s;
            cin >> s;
            mp[s]=i;
        }

        for(int i = 0; i < R; i++) {
            string u,v;
            cin >> u >> v;
            adjL[mp[u]].push_back(mp[v]);
            adjL[mp[v]].push_back(mp[u]);
        }

        int mx=0;
        for(int i=1; i<=C; i++) if (!vis[i]) {
            cnt=0;
            dfs(i);
            mx = max(mx,cnt);
        }
        
        cout << mx << el;
    }

    return 0;
}
