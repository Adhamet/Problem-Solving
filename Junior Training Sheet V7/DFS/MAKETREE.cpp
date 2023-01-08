//SPOJ
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

const int N = 100, oo = 1e9+5;

vector<int> parent;
vector<int> vis;
int findparent(int u)
{
    if(!vis[u])
        vis[u] = 1;
    if (parent[u] == 0)
        return u;
    return findparent(parent[u]);
}  

int main()
{
    /* #ifndef ONLINE_JUDGE
	    freopen("test.txt", "rt", stdin);
    #endif */

    //adhamet;

    int n,s,wishes,son;
    cin >> n >> s;
    parent = vector<int>(n);
    vis = vector<int>(n);
    fill(parent.begin(), parent.end(), 0);

    for(int i = 1; i <= s; i++)
    {
        cin >> wishes;
        for(int j = 1; j <= wishes; j++)
        {
            cin >> son;
            if(parent[son] != 0)
                son = findparent(son);
            parent[son]=i;
        }
    }
    
    for(int i = 0; i < n; i++) if(!vis[i] && parent[son] != i)
        parent[i] = parent[son];

    for(int i = 1; i <= n; i++)
        cout << parent[i] << el;

    return 0;
}