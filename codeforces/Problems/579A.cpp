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

int main()
{
    adhamet
    
    int n,ans = 0;
    cin >> n;

    while (n != 0) {
        if (n%2 == 1)
            ans++;
        n/=2;
    }
    cout << ans;

    return 0;
}
