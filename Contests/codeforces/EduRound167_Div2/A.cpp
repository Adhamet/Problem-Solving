#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
/* const int N = 2e5+5, oo=INT_MAX+7, MOD=INT_MAX+7; */

int main()
{
    adhamet;

    int t;  cin >> t;
    while(t--) {
        ll x,y;    cin >> x >> y;
        if(y<=-2) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
