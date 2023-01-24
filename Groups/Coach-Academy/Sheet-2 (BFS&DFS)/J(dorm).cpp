#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define f first
#define s second
const int N = 2e4+5, oo = 1e9;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<pair<int,int>> adj[N];
int di, in[N],out[N], last;
void dfs(int node)
{
    last = node;
    for(auto child: adj[node])
    {
         dfs(child.first);
         di=min(di,child.second);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({b,d});
        in[b]++;
        out[a]++;
    }
    vector<pair<pair<int,int>,int>> results;
    for(int i = 1; i <= n; i++)
    {
        if(in[i]==0 && out[i]>0)
        {
            di = oo;
            dfs(i);
            results.push_back({{i,last},di});
        }
    }
    cout << results.size() << endl;
    for(auto result : results)
        cout << result.f.f << " " << result.f.s << " " << result.second << endl;
}