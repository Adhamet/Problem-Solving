// Codeforces
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

struct Rect {
	ll x1,x2,y1,y2;
	ll area() { return (y2-y1)*(x2-x1); }
};

ll aoi(Rect p, Rect q) { // area of intersection
	ll lenOfINT = max(min(p.x2, q.x2) - max(p.x1, q.x1), (ll)0);
	ll widOfINT = max(min(p.y2, q.y2) - max(p.y1, q.y1), (ll)0);
	return lenOfINT * widOfINT;
}

ll aoi_three(Rect a, Rect b, Rect c) {
	ll lenOfINT = max(min(min(a.x2, b.x2), c.x2) - max(max(a.x1, b.x1), c.x1), (ll)0);
	ll widOfINT = max(min(min(a.y2, b.y2), c.y2) - max(max(a.y1, b.y1), c.y1), (ll)0);
	return lenOfINT * widOfINT;
}

int main()
{
    adhamet;

    Rect w,b1,b2;

    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
	
    if (w.area() - (aoi(w, b1) + aoi(w, b2)) + aoi_three(w, b1, b2))
    	cout << "YES\n";
	else cout << "NO\n";


    return 0;
}