#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define fst first
#define scd second
#define el '\n'

i64 lcm(i64 a, i64 b) {
	return a / __gcd(a, b) * b;
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	i64 x;	cin >> x;
	i64 a = 1, b = x;
	auto lcm = [](i64 a, i64 b) { return a / __gcd(a, b) * b; };
	for (i64 i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			i64 aa = i, bb = (x / i);
			if (lcm(aa, bb) == x && max(aa, bb) < max(a, b))
				tie(a,b) = make_pair(aa, bb);
		}
	} return cout << a << ' ' << b, 0;
}
