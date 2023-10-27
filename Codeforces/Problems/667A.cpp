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
const long double PI = acos(-1.0);

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	double d,h,v,e;
	cin >> d >> h >> v >> e;
	double t = (4*v)/(PI*d*d);
	if ( t > e ) cout << fixed << setprecision(12) << "YES\n" << h / (t - e);
	else cout << "NO\n";
	
    return 0;
}