#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define el '\n'
#define i64 int64_t

const int64_t MXN = 1e5+5;

i64 bsqrt(i64 x) {
	if (x == 0 || x == 1) return x;

	i64 l = 1, r = x, ans = 0;
	while (l <= r) {
		i64 mid = l + (r - l) / 2;
		if (mid <= x / mid) l = mid + 1, ans = mid;
		else r = mid - 1;
	}

	return ans;
}

bool isPerfSqr(i64 xx) {
	i64 x = bsqrt(xx);
	return (x * x) == xx;
}

int32_t main() {
	i64 x;
	scanf("%lld", &x);
	
	i64 xx = x * x, cc, aa;
	for (i64 i = 1; i < MXN; ++i) {
		i64 ii = i * i;

		// op1 = C = X + B
		cc = xx + ii;
		if (isPerfSqr(cc)) {
			return printf("%lld %lld", i, bsqrt(cc)), 0;
		}

		// op2: X = A + B -> A = X - B
		aa = xx - ii;
		if (aa && isPerfSqr(aa)) {
			return printf("%lld %lld", bsqrt(aa), i), 0;
		}
	}

	return printf("%d", -1), 0;
}
