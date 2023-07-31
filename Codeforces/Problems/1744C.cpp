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

int solve()
{
    int n;
    char col;
    string s;
    cin >> n >> col >> s;
    if (col == 'g') return cout << 0 << el, 0;
    s += s;

    int sec, ans=0;
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == col) {
            sec=0;
            while ( s[i] != 'g' && i < s.size() )
                sec++, i++;
            if ( sec > ans ) ans = sec;
        }
    }
    cout << ans << el;

    return 0;
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
