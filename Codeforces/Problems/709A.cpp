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
    int n,b,d,temp,empty=0;
    ll totalSize = 0;
    cin >> n >> b >> d;

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if ( temp <= b )
            totalSize += temp;
        if ( totalSize > d ) { empty++; totalSize = 0; }
    }
    cout << empty;
}

int main()
{
    adhamet
    
    solve();
    return 0;
}