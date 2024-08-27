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
    int n,x,sol=1e9;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        sol = min(x,sol);
    }
    cout << sol << el;
}

int main() 
{/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */

    int t=1;
    cin >> t;
    while(t--) 
        solve();

	return 0;
}
