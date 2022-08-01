#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>

const int N = 1e5+10, oo = 1e9;
int par[N], sz[N], n, m;

void init()
{
    for(int i = 1; i <= n; i++)
        par[i] = i, sz[i] = 1;
}
int findparent(int u)
{
    if (par[u] == u)
        return u;
    return par[u] = findparent(par[u]);
}
bool isCyclic = false;
void connect(int u, int v)
{
    u = findparent(u);
    v = findparent(v);
    if ( u == v )
    {
        isCyclic = true;
        return;
    }
    if (sz[u] < sz[v])
        par[u] = v, sz[v] += sz[u];
    else
        par[v] = u, sz[u] += sz[v];
}
bool isConn(int u, int v)
{
    return (findparent(u) == findparent(v));
}

int main()
{
    fff;
    n=26;
    init();
    int sz;
    cin >> sz;
    string str1,str2;
    cin >> str1 >> str2;
    vector<pair<char, char>> ans;
    for(int i = 0; i < sz; i++)
    {
        int u = str1[i] - 'a', v = str2[i] - 'a';
        if(isConn(u,v))
            continue;
        ans.push_back({str1[i], str2[i]});
        connect(u,v);
    }
    
    cout << ans.size() << endl;
    for(auto conn : ans)
        cout << conn.F << " " << conn.S << endl;
}

