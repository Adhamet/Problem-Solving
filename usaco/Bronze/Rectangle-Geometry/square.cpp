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
};

int main()
{
    adhamet;
    setIO("square");

    Rect p,q;

    cin >> p.x1 >> p.y1 >> p.x2 >> p.y2;
    cin >> q.x1 >> q.y1 >> q.x2 >> q.y2;

    int optionOne = max(q.x2,p.x2) - min(q.x1,p.x1);
    int optionTwo = max(q.y2,p.y2) - min(q.y1,p.y1);
    int sideL = max(optionOne, optionTwo);
	
	cout << sideL * sideL;

    return 0;
}