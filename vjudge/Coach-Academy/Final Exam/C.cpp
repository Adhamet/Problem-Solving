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

const int N = 3e5+10, M = 23;
bool cyclic = 0;
int n, m, k;
ll ancestor[N][M], sp[N][M], a[N], lv[N], par[N], sz[N];
vector<vector<pair<ll,ll>>> g(N);

void init(int n)
{
    for(int i = 1; i <= n; i++) {
        par[i]=i;
        sz[i]=i;
    }
}

int findParent(int u ) {
    if(par[u] == u)
        return u;
    return par[u] = findParent(par[u]);
}
void connect(int u, int v){
    u = findParent(u);
    v = findParent(v);
    if( u == v ) {
        cyclic = true;
    }

    if(sz[v] < sz[u]) par[v] = u, sz[u] += sz[v];
    else par[u] = v, sz[v] += sz[u];
}
bool isConnect(int u, int v) {
    return (findParent(u) == findParent(v));
}

void dfs(int node, int par, int cost)
{
    lv[node] = lv[par]+1;
    ancestor[node][0] = par;
    sp[node][0] = cost;   

    for(int i = 1; i < M; i++) {
        ll pap = ancestor[node][i-1];
        ancestor[node][i] = ancestor[pap][i-1];
        sp[node][i] = min(sp[pap][i-1], sp[node][i-1]);
    }

    for(auto child: g[node]) {
        if ( child.F == par ) continue;
        dfs(child.F,node, child.S);
    }
}

ll findKthancestor(int u, int k)
{
    for(int i = M-1; i>=0; i--)
        if(k&(1<<i)) u = ancestor[u][i];

    return u;
}

int getLCA(int u, int v)
{
    if(lv[u] < lv[v])
        swap(u,v);
    u = findKthancestor(u, lv[u] - lv[v]);
    if(u == v) return v;

    for(int i = M-1; i>=0; i--) {
        if(ancestor[u][i] == ancestor[v][i])
            continue;
        u=ancestor[u][i];
        v=ancestor[v][i];
    }

    return ancestor[u][0];
}

ll maxim(int u, int l1, int v, int l2)
{
    ll mm=1e9;
    for(int i = M-1; i >= 0; i--) {
        if((1<<i)<=l1) {
            l1 -= (1<<i);
            mm = min(mm, sp[u][i]);
            u = findKthancestor(u, (1<<i));
        }
        if((1<<i) <= 12) {
            l2 -= (1<<i);
            mm = min(mm, sp[v][i]);
            v=findKthancestor(v, (1<<i));
        }
    }
    return mm;
}

ll res(int u, int v) {
    int mm = getLCA(u,v);
    return maxim(u, lv[u] - lv[mm], v, lv[v] - lv[mm]);
}

void solve()
{
    while(cin >> n >> m >> k)
    {
        init(n);
        vector<pair < ll , pair<ll,ll> >> vec;

        for(int i = 0; i < m; i++)
        {
            ll a,b,c;
            cin >> a >> b >> c;
            vec.push_back({c, {a,b}});
        }

        sort(vec.begin(), vec.end());
        for(int i = m-1; i >= 0; i--) {
            ll a = vec[i].S.F, b = vec[i].S.S, c = vec[i].F;
            if (isConnect(a,b))
                continue;
            connect(a,b);
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }

        dfs(1,1,0);

        while(k--)
        {
            int a,b;
            cin >> a >> b;
            cout << res(a,b) << endl;
        }
        for(int i = 1; i <= n; i++)
        {
            g[i].clear();
            lv[i] = 0;
            for(int j = 0; j<M; j++)
                sp[i][j] = ancestor[i][j] = 0;
        }
    }
}

int main()
{
    adhamet
    solve();

    return 0;
}

