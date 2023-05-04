// Kuriyama Mirai's Stones
#include <bits/stdc++.h>
 
using namespace std;
#define adhamett ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define F first
#define S second
#define el '\n'

void solve()
{
    int n,m,type,l,r;
    cin >> n;
    ll v[n + 1];
    ll u[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        u[i] = v[i];
    }

    sort(u + 1, u + 1 + n);

    for (int i = 1; i <= n; i++)
        v[i] = v[i] + (i > 1 ? v[i-1] : 0);
    for (int i = 1; i <= n; i++)
        u[i] = u[i] + (i > 1 ? u[i-1] : 0);

    cin >> m;
    while (m--)
    {
        cin >> type >> l >> r;
        if (type == 1)
            cout << v[r] - (l == 1 ? 0 : v[l-1]) << el;
        else
            cout << u[r] - (l == 1 ? 0 : u[l-1]) << el;
    }
}

int main()
{
    adhamett
    
    solve();

    return 0;
}