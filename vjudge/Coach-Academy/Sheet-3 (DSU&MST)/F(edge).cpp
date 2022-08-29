#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>
const int N = 1e5+10, oo = 1e9, MOD = 1e9+7;
int par[N], cnt[N];

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
    cnt[v] += cnt[u];
}
bool isConn(int u, int v)
{
    return (findparent(u) == findparent(v));
}

ll fastPower(ll base, ll power)
{
    ll result = 1;
    while(power > 0)
    {

        if (power&1)
            result = (result*base) % MOD;
        base = (base*base) % MOD;
        power = power / 2;
    }
    return result;
}

int main()
{
    fff;
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        par[i] = i;
        cnt[i] = 1;
    }
    ll result = fastPower(n,k);

    for(int i = 1; i < n; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if ( c == 0 )
        {
            connect(a,b);
        }
    }

    for(int i = 1; i<=n; i++)
    {
        if(findparent(i) == i)
        {
            result = (result - fastPower(cnt[i],k)+MOD) % MOD;
        }
    }
    cout << result << '\n';
}