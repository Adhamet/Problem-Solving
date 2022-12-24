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
    int n,m,original;
    int i = 1;
    cin >> original >> m;
    while(true)
    {
        n = original * i;
        if (n%10 == 0) { break; }
        else if ( (n-m)%10 == 0 ) { break; }
        i++;
    }   
    cout << i;
}

int main()
{
    adhamet
    
    solve();
    return 0;
}