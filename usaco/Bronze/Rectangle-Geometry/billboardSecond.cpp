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

void setIO(string name = "") {
	if (name.size()) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);	
	}
}

struct Rect {
	int x1,x2,y1,y2;
	int area() { return (y2-y1)*(x2-x1); }
};

Rect getIntersect(Rect rectOne, Rect rectTwo) {
	Rect intersection;

	intersection.x1 = max(rectOne.x1, rectTwo.x1);
	intersection.y1 = max(rectOne.y1, rectTwo.y1);
	intersection.x2 = min(rectOne.x2, rectTwo.x2);
	intersection.y2 = min(rectOne.y2, rectTwo.y2);

	return intersection;
}

int main()
{
    adhamet;
    setIO("billboard");

    Rect p,q;
    cin >> p.x1 >> p.y1 >> p.x2 >> p.y2;
    cin >> q.x1 >> q.y1 >> q.x2 >> q.y2;

    Rect i = getIntersect(p,q);

    if ( (i.x1 <= p.x1 && i.x2 >= p.x2) &&
    		(i.y1 <= p.y1 && i.y2 >= p.y2)) {
    	cout << 0;
    }
    else if ( (i.x1 <= p.x1 && i.x2 >= p.x2) ||
    		(i.y1 <= p.y1 && i.y2 >= p.y2)) {
    	cout << p.area() - i.area();
    }
	else {
		cout << p.area();
	}
	
    return 0;
}