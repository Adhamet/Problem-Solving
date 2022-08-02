#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>

const int N = 1e5+10, oo = 1e9;
int par[N], cnt[N], n;

int findparent(int u)
{
    if (par[u] == u)
        return u;
    return findparent(par[u]);
}
void connect(int u, int v)
{
    u = findparent(u);
    v = findparent(v);
    if ( u == v )
        return;
    par[u] = v;
}
bool isConn(int u, int v)
{
    return (findparent(u) == findparent(v));
}

int main()
{
    fff;
    while(cin >> n)
    {
        for(int i = 1; i <= n; i++)
            par[i]=i;
        
        vector<pair<int, intPair>> fibers;
        for(int i = 1; i<=n; i++)
            for(int j = 1; j<=n; j++)
            {
                int cost;
                cin >> cost;
                fibers.push_back({cost,{i,j}});
            }
        sort(fibers.begin(),fibers.end());
        int ans = 0;
        for(auto fiber: fibers)
        {
            int x = fiber.S.F, y = fiber.S.S;
            int c = fiber.F;
            if(!isConn(x,y))
            {
                ans += c;
                connect(x,y);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
