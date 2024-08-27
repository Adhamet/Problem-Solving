#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
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
    
	int r1,r2,c1,c2,d1,d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    for(int i = 1; i < 10; i++)
        for(int j = 1; j < 10; j++) {
                if ( i == j ) continue;
                for (int k = 1; k < 10; k++) 
                {
                    if ( i == k || j == k ) continue;
                    for (int l = 1; l < 10; l++) {
                        if ( i == l || j == l || k == l ) continue;
                        if ( i + j == r1 && k + l == r2 && i + k == c1 && j + l == c2 && i + l == d1 && j + k == d2 )
                            return cout << i << " " << j << el << k << " " << l << el, 0;
                    }
                }
        }
    cout << -1 << el;

	return 0;
}
