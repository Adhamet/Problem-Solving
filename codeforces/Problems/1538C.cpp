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

void solve()
{
    int n,l,r;
    cin >> n >> l >> r;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int pt1 = 0, pt2 = 1, mid, ans = 0;
    while ( pt1 < n - 1 ) // (5,8)    1 2 3 4 5
    {

    }
    cout << ans << el;
}

int main() 
{
/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
    int t;
    cin >> t;
    while(t--)
        solve();

	return 0;
}
