#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	vector<i64> primes = {2,3,5,7,11,13,17,19};
	i64 num = 1;
	for (auto &p: primes) {
		i64 x = p;
		while (x * p < 20) x *= p;
		num *= x;
	}

	return cout << num, 0;
}
