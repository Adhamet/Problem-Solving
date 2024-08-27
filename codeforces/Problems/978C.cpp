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
    
    int n,m;
    cin >> n >> m;
    ll dorm[n+2] = {}, s[n+2] = {}, b[m+2] = {};

    for(int i = 1; i <= n; i++) cin >> dorm[i];
    for(int i = 1; i <= n; i++) s[i] = s[i-1] + dorm[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    for(int i = 1; i <= m; i++) {
        int l=0,r=n-1,dorm_idx=0;
        while(l <= r) {
            int mid = l + (r - l)/2;

            if (s[mid] < b[i]) dorm_idx = mid, l = mid + 1;
            else r = mid - 1;
        }
        cout << dorm_idx + 1 << " ";
        cout << b[i] - s[dorm_idx] << el;
    }

	return 0;
}
