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
    int k, arr[12], c = 0;
    cin >> k;

    for (int i = 0; i < 12; i++) cin >> arr[i];
    sort(arr, arr+12, greater<int>());

    for (int i = 0; i < 12; i++) {
        if (k > 0) 
        {
            k -= arr[i];
            c++;
        }
    }

    if (k <= 0) cout << c;
    else cout << -1;
}

int main()
{
    adhamett
    
    solve();

    return 0;
}