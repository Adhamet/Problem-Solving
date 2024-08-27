#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int t;	cin >> t;
    while(t--) {
    	int W,H;	
    	cin >> W >> H;

    	int x1,y1,x2,y2;	cin >> x1 >> y1 >> x2 >> y2;

    	int w,h;	cin >> w >> h;

    	int moves = 1e9;
    	if (x2 - x1 + w <= W) {
    		moves = min(moves, max(0, w-x1));
    		moves = min(moves, max(0, x2 - (W-w)));
    	}
    	if (y2 - y1 + h <= H) {
    		moves = min(moves, max(0, h-y1));
    		moves = min(moves, max(0, y2 - (H-h))); // 4 - (17-4) = 4 - 12 = 
    	}

    	if (moves == 1e9) cout << -1 << el;
		else cout << fixed << setprecision(9) << (double)moves << el;
    }
	
    return 0;
}