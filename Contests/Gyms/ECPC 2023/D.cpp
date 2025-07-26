#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		i64 a,b,c,d;	cin >> a >> b >> c >> d;
		bool found = false;

		i64 ans = 0, mxx = abs(d);
	
		if (d == 0) found = true, ans = 0;
		else {
			for (int x = 1; x <= mxx; ++x) {
				i64 eq = a*x*x*x + b*x*x + c*x + d;
				if (eq == 0) {
					found = true;
					ans = x;
					break;
				}

				i64 neq = a*(-x)*(-x)*(-x) + b*(-x)*(-x) + c*(-x) + d;
				if (neq == 0) {
					found = true;
					ans = -x;
					break;
				}
			}
		}

		if (found) cout << "Yes" << el << ans << el;
		else cout << "No" << el;
	}

	return 0;
}
