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
    int n,k,i=0,result=0;
    cin >> n >> k;

    if( n == k )
        cout << 1;
    else
        cout << -1;

    while(k < n && result < n) {
        i++;
        result = k;
        result*=i;
    }
    cout << i;
}

int main()
{
    adhamet
    
    solve();
    return 0;
}