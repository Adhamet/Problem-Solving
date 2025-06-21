#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

// 1,1 dr / -1,-1 ul / 1,-1 dl / -1,1 ur
int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, s, cnt = 0; cin >> n >> s;
		for (int i = 0; i < n; ++i) {
			i64 dx,dy,x,y; cin >> dx >> dy >> x >> y;
			i64 arrow = x*dy - y*dx;
			if (arrow % s == 0) {
				i64 v = arrow/s;
				i64 dir = (dy == 1)? 1: 0;
				i64 resvec = (v + dir*dx) * dy;
				if ((resvec*s - x) * dx >= 0) cnt += 1;
			}
		} cout << cnt << el;
	} return 0;
}
