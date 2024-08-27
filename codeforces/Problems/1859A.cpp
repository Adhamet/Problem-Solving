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
{/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n+2];
        for(int i = 1; i <= n; i++) cin >> arr[i];
        sort(arr+1,arr+n+1);
        int cnt = 0;
        for(int i = 1; i <= n; i++) if ( arr[i] < arr[i+1] ) {
            cnt = i;
            break;
        }
        if (cnt && cnt<n) {
            cout << cnt << " " << n - cnt << el;
            for(int i = 1; i <= cnt; i++) cout << arr[i] << " "; cout << el;
            for(int i = cnt+1; i <= n; i++) cout << arr[i] << " "; cout << el;
        }
        else cout << -1 << el;
    }

	return 0;
}
