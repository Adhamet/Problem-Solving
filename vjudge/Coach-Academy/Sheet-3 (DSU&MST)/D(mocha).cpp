#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>

const int N = 1e3+10, oo = 1e9;
int n;

int findParent(int u, ll par[])
{
    if (par[u] == u)
        return u;
    return par[u] = findParent(par[u], par);
}
void connect(int u, int v, ll par[])
{
    u = findParent(u, par);
    v = findParent(v, par);
    if ( u == v )
        return;
    par[u] = v;
}
bool isConn(int u, int v, ll par[])
{
    return (findParent(u, par) == findParent(v, par));
}

int main()
{
    fff;
    cin >> n;
    int mMocha, mDiana;
    cin >> mMocha >> mDiana;
    ll parMocha[n], parDiana[n];
    for(int i = 1; i <= n; i++)
    {   
        parMocha[i] = i;
        parDiana[i] = i;
    }
    for(int i = 1; i <= mMocha; i++)
    {
        int u,v;
        cin >> u >> v;
        connect(u,v,parMocha);
    }
    for(int i = 1; i <= mDiana; i++)
    {
        int u,v;
        cin >> u >> v;
        connect(u,v,parDiana);
    }

    if (n == mMocha+1 || n == mDiana+1)
        return cout << 0 << endl, 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; i++)
        {
            if ( n == mMocha+1 || n == mDiana+1 )
                break;
            else
                if( i!=j && !isConn(i,j,parMocha) && !isConn(i,j,parDiana))
                {
                    connect(i,j,parMocha);
                    connect(i,j,parDiana);
                    cout << i << " " << j << endl;
                }
        }
}
