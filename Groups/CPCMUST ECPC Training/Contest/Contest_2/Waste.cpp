#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el endl

void solve() // 13 37 42     
             // 0 0 0 40 47
{
    int c1,c2,c3;
    cin >> c1 >> c2 >> c3;

    int a1,a2,a3,a4,a5;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;

    c1 -= a1, c2 -= a2, c3 -= a3;
    if ( c1 >= a4 ) c1 -= a4, a4 = 0;
    else if ( c1 > 0 ) a4 -= c1, c1 = 0;

    if ( c2 >= a5 ) c2 -= a5, a5 = 0;
    else if ( c2 > 0 ) a5 -= c2, c2 = 0;

    c3 -= (a4 + a5);
    if ( c1 < 0 || c2 < 0 || c3 < 0 ) cout << "NO" << el;
    else cout << "YES" << el;   
}

int main() 
{
    /*
    #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
    #endif
    */
    
    adhamet;
    
    int t;
    cin >> t;
    while(t--)
        solve();
 
	return 0;
}
