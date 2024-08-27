#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define ull unsigned long long
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'

int main() 
{
/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
    int n;
    cin >> n;
    int weight[n];
    for(int i = 0; i < n; i++) cin >> weight[i];

    int pt1 = 0, pt2 = n - 1;
    ll sum1 = 0, sum2 = 0, ans = 0;
    while ( true ) {
        if( pt1 > pt2 ) {
            if ( sum1 == sum2 )
                ans = max(ans,sum1);
            break;
        }

        if ( sum1 < sum2 ) sum1 += weight[pt1], pt1++;
        else if ( sum1 > sum2 ) sum2 += weight[pt2], pt2--;
        else ans = max(ans, sum1), sum1 += weight[pt1], pt1++;
    }
    cout << ans << el;

    return 0;
}
