#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>

const int N = 1e5+10, oo = 1e9;
int par[N], took[N];

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
    int n,m;
    cin >> n >> m;
    int cnt = 0;

    for(int i = 1; i<=n; i++)
        par[i]=i;

    vector<int> employee[N];
    for(int i = 1; i<=n; i++)
    {
        int k;
        cin >> k;
        if(k == 0)
            cnt++;
        int lang[k];
        for(int z = 0; z < k; z++)
        {
            cin >> lang[z];
            took[lang[z]]++;
            if(z>0)
                connect(lang[z],lang[z-1]); 
        }
    }
    int c = 0;
    for(int i = 1; i <= m; i++)
        if(findparent(i) == i && took[i])
            c++;   
    if(c>0)
        cnt+=(c-1);
        
    cout << cnt << endl; 
}