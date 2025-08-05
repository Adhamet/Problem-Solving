#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	i64 ans = 1;
	for (int i = 1; i <= 20; ++i) ans = lcm(ans, (i64)i);
	return cout << ans, 0;
}
