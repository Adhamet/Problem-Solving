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
    int n,x;
    cin >> n >> x;
    int count = 0;
    for (int i = 1; i <= n; i++) if ( x % i == 0 && x/i <= n)
        count++;
    cout << count << el;
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
