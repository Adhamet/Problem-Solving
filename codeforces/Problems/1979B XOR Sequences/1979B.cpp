#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int t;  cin >> t;
    while(t--) {
        int x,y;    cin >> x >> y;
        for(int i = 0; i < 32; i++) {
            if( (x & (1<<i)) != (y & (1<<i)) ) {
                cout << (1ll << i) << el;
                break;
            }
        }
    }

    return 0;
}
