#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int SZ = (1 << 20) + 3;
int32_t dp[2][SZ]; // if the same xor value was set in a prev even len

int32_t main() {
	int32_t n, x = 0;
	scanf("%d", &n);

	vector<int32_t> a(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	int64_t ans = 0;
	dp[1][0] = 1; // at even length & starting xor pos
	for (int i = 0; i < n; ++i) {
		x ^= a[i];
		ans += dp[i % 2][x];
		dp[i % 2][x] += 1;
	}

	return printf("%lld", ans), 0;
}
