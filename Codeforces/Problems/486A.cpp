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
    ll n,a;
    cin >> n;
    if(n%2==0) a=n/2;
    else a=((n+1) / 2) * (-1);
    cout << a << endl;
}

int main()
{
    adhamet
    
    solve();
    return 0;
}