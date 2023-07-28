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
    
    int n, x;
    bool ok = true;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;

        if ( x % 2 ) {
            if (ok)
                x++, x = x / 2, ok = !ok;
            else
                x--, x = x / 2, ok = !ok;
            cout << x << el;
        }
        else {
            x /= 2;
            cout << x << el;
        }
    }

	return 0;
}
