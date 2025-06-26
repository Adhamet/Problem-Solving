#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;	cin >> t;
	while (t--) {
		int a, b;	cin >> a >> b;
		int ans = b - a;
		for (int i = 0; i < ans; ++i) {
			int bb = b + i;
			if ((a | bb) == bb) {
				ans = min(ans, i + 1);
				break;
			}
		} 

		cout << ans << el;
	} return 0;
}
