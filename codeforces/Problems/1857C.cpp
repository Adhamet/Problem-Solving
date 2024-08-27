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
    while(t--) {
        int n;
        cin >> n;
        int new_n = ( n * (n-1) ) / 2;
        int b[new_n];
        for(int i = 0; i < new_n; i++) cin >> b[i];
        sort(b,b+(new_n));
        for(int i = 0; i < new_n; i += --n) cout << b[i] << ' ';
        cout << b[(new_n)-1] << el;
    }

	return 0;
}
