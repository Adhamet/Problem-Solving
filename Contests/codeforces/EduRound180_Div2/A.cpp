#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;	cin >> t;
	while (t--) {
		int a, x, y;	cin >> a >> x >> y;
		if (x > y) swap(x, y);
		if (x < a && y > a) cout << "NO" << el;
		else cout << "YES" << el;
	}  return 0;
}
