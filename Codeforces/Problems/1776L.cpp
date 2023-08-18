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
    
    long long rounds; string signs;
    cin >> rounds >> signs;
    long long pos = count(signs.begin(),signs.end(),'+');
    long long neg = rounds - pos;
    
    int c;
    cin >> c;
    while(c--) {
        long long a,b;
        cin >> a >> b;
        
        if ( a == b ) cout << ( pos == neg ? "YES\n": "NO\n");
        else cout << (((neg-pos)*b%(a-b) || (neg-pos)*b/(a-b) < -neg || (neg-pos)*b/(a-b) > pos) ? "NO\n": "YES\n");
    }
	return 0;
}
