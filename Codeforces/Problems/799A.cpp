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
    int n,t,k,d;
    cin >> n >> t >> k >> d;
    int sOvnT = d;
    while(sOvnT >= 0) {
        n-=k;
        sOvnT-=t;
    }
    if ( ( n > 0 && sOvnT < 0 ) || ( sOvnT == 0 && n >= sOvnT + 1 ) ) cout << "YES";
    else cout << "NO";
}

int main()
{
    adhamet
    
    solve();
    return 0;
}