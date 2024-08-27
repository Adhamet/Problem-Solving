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
    int n;
    cin >> n;
    int coins[n], sum1 = 0, sum2 = 0, cnt = 0;
    for(int i = 0; i < n; i++) { cin >> coins[i]; sum1 += coins[i]; }
    sum1 = sum1 / 2;
    sort(coins, coins+n);

    for(int i = n - 1; i >= 0; i--) {
        sum2 += coins[i];
        cnt++;
        if(sum1 < sum2) break;
    }
    cout << cnt;
}

int main()
{
    adhamet

    solve();
    return 0;
}