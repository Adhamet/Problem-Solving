#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fff ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define F first
#define S second
#define intPair pair<int,int>

const int N = 1e5+10, oo = 1e9;
int par[N];


//-------------------------------------
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
//--------------------------------------


int main()
{
    fff;
    int T;
    cin >> T;
    while(T--)
    {
        int n,m;
        string s;
        cin >> n;
        for(int i = 1; i <= n; i++)
            par[i] = i;
        vector<pair<int,intPair>> vec;
        for(int i = 1; i <= n; i++)
        {
            cin >> s >> m;
            for(int j = 1; j <= m; j++)
            {
                int city,cost;
                cin >> city >> cost;    
                vec.push_back( {cost, {i,city}} );
            }
        }
        sort(vec.begin(), vec.end());
        int result = 0;

        for(auto i: vec)
        {
            int x = i.second.first, y = i.second.second;
            int c = i.first;
            if ( isConn(x,y) )
                continue;
            result+=c;
            connect(x,y);
        }
        cout << result << '\n';
    }
}