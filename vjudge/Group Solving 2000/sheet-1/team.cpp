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

const ll N = 1e15;
int ans=0;

void solve()
{
    int x, sols=0;
    for(int i = 0; i < 3; i++) {
        cin >> x;
        if ( x == 1 ) sols++;
    }
    if (sols >= 2) ans++;
}

int main()  
{
    adhamet

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    cout << ans;

    return 0;
}