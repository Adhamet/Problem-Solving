#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

// void setIO(string name = "") {
// 	if (name.size()) {
// 		freopen((name+".in").c_str(), "r", stdin);
// 		freopen((name+".out").c_str(), "w", stdout);	
// 	}
// }

int main()
{
    // setIO("blist");
    int t;
    cin >> t;
    while (t--) {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        
        int ans = 0;
        if ( (p1+p2+p3) % 2 != 0 ) {
        	cout << -1 << el;
        	continue;
        }

        int fps = p2+p1;
        if(p3 > fps) { // 1 1 2
        	ans += fps;
        	p3-=fps;
        } else {       // 1 1 2
        	ans += p3; // ans = 2
        	fps-=p3;   // 0
        	ans += fps / 2;
        }

        cout << ans << el;
    }
    return 0;
}