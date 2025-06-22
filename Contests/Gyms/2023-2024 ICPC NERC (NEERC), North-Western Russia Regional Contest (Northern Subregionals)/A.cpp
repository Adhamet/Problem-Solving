#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	i64 a, b, c, d; cin >> a >> b >> c >> d;
	i64 x = min(a,c) * min(b,d);
	i64 y = min(a,d) * min(b,c);
	return cout << max(x,y), 0;
}
