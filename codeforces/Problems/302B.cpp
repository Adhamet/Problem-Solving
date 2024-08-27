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
    
    int n,m,c,t;
    cin >> n >> m;

    int arr[n+2];
    arr[0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> c >> t;
        arr[i] = arr[i-1] + c * t;
    }

    int min;
    int l, r, mid, ans;
    while (m--)
    {
        l = 1, r = n;
        cin >> min;
        
        while (l != r) {
            mid = l + (r - l)/2;

            if ( arr[mid] < min ) l = mid + 1;
            else if ( arr[mid] > min ) r = mid;
            else l = mid + 1;
        }
        cout << l << el;
    }
	return 0;
}
