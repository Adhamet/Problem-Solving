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
    
    int n,q;
    cin >> n >> q;
    int arr[n+2], freq[n+2];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 3; i <= n; i++)
        freq[i] = freq[i-1] + ( (arr[i-2] >= arr[i-1]) && (arr[i-1] >= arr[i]) );
    
    int l,r;
    while(q--) {
        cin >> l >> r;
        (l == r)? cout << "1": cout << (r - l + 1 - freq[r] + freq[l + 1]);
        cout << el;
    }

	return 0;
}
