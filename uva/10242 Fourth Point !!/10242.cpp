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

int main()
{
	adhamet
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	
	double x1,y1,x2,y2,x3,y3,x4,y4;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
		cout << fixed << setprecision(3);
		if (x1 == x3 && y1 == y3) cout << (x2+x4)-x1 << " " << (y2+y4)-y1;
		else if (x1 == x4 && y1 == y4) cout << (x2+x3)-x1 << " " << (y2+y3)-y1;
		else if (x2 == x3 && y2 == y3) cout << (x1+x4)-x2 << " " << (y1+y4)-y2;
		else cout << (x1+x3)-x2 << " " << (y1+y3)-y2;
		cout << '\n';
	}
	
    return 0;
}