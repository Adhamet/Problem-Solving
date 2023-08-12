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

int f(int n, int m) {
    if (n == m) return 1;
    if (n % 3 != 0) return 0;
    return (f(n/3,m) || f(n/3*2,m));
}
int main() 
{/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet
    
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        cout << (f(n,m)? "YES": "NO") << '\n';
    }

	return 0;
}
