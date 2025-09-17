#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;

int main() {
	int t;	scanf("%d", &t);
	while (t--) {
		i64 x, n;	scanf("%lld%lld", &x, &n);
		if (n % 4 == 0) printf("%lld\n", x);
		else if (n % 4 == 3) {
			if (x % 2 == 0) printf("%lld\n", x + (i64)ceil(n / 4.0) * 4);
			else printf("%lld\n", x - (i64)ceil(n / 4.0) * 4);
		} else if (n % 4 == 2) {
			if (x % 2 == 0) printf("%lld\n", x + 1);
			else printf("%lld\n", x - 1);
		} else {
			if (x % 2 == 0) printf("%lld\n", x - n);
			else printf("%lld\n", x + n);
		}
	}
	return 0;
}
