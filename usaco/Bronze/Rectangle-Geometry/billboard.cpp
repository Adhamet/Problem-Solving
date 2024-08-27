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
	int x1,y1,x2,y2;
	int area() { return (y2-y1) * (x2-x1); }
};

int intersect(Rect p, Rect q) {
	int lenOfINT = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
	int widOfINT = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
	return lenOfINT * widOfINT;
}

int main()
{
    adhamet;
    setIO("billboard");

	Rect aaa,ggg,truck;
	cin >> aaa.x1 >> aaa.y1 >> aaa.x2 >> aaa.y2;
	cin >> ggg.x1 >> ggg.y1 >> ggg.x2 >> ggg.y2;
	cin >> truck.x1 >> truck.y1 >> truck.x2 >> truck.y2;
	cout << aaa.area() + ggg.area() - intersect(aaa,truck) - intersect(ggg,truck);
	
    return 0;
}