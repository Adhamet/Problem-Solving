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

void solve()
{
    int x,y;
    ll steps,s;
    cin >> x >> y >> steps;

    s = abs(x) + abs(y);

    if ( steps % 2 == 0 && s <= steps && s % 2 == 0 || steps % 2 == 1 && s <= steps && s % 2 == 1 )
        cout << "Yes";
    else cout << "No";
    return;
}

int main()
{
    adhamet
    
    int t = 1;
    //t = 4;
    while(t--) {
        solve();
    }
    return 0;
}
