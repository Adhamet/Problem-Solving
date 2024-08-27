#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    adhamet;

    int d,q;
	cin >> d >> q;

    while (q--) {
        int x, dist = d - 1, speed = 2;  
		cin >> x;
        
		int ans = 1;
        while (dist > 0) {
            dist -= (speed <= x ? speed++: x++);
            ans++;
        }
        cout << ans << el;
    }

    return 0;
}
