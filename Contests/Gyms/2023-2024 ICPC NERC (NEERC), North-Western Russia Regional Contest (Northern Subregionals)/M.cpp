#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	i64 d; cin >> d;
	string s = "";
	i64 rem = 0;
	for (int i = 1; i <= 1e6+5; ++i) {
		s += '1';
		rem = (rem*10+1)%d;
		if (rem == 0 && i % d == 0) break;
	}

	return cout << s,0;
}
