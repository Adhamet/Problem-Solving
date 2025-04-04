#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define i64 int64_t

int32_t main() {
	i64 x, m, k;
	scanf("%lld", &x);
	if (x == 1 || x == 2) return puts("-1"), 0;

	if (x % 2 == 0) {
		i64 a = (x / 2);
		m = a * a - 1;
		k = a * a + 1;
	} else {
		m = (x * x - 1) / 2;
		k = (x * x + 1) / 2;
	}

	return printf("%lld %lld", m, k);
}
