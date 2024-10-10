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
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	int r,s,m,n,p,q;	cin >> r >> s >> m >> n >> p >> q;
	int ax = 0, ay = 0;
	int bx = r, by = s;
	int t = 0;

	while(ax < bx && ay < by) {
		ax += m; ay += n;
		bx -= p; by -= q;
		t++;
	}
	if (ax == bx && ay == by) cout << t << '\n';
	else cout << -1 << '\n';
	
    return 0;
}