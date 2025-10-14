#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	while (a < c) {
		if (a + b > c) break;
		a += b;
		c -= d;
	}

	return std::cout << max(a, c), 0;
}

