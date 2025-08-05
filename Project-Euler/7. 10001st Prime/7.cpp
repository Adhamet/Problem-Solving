#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int n = 1e4 + 1;
	vector<int> primes;	primes.push_back(2);

	for (int i = 3; i <= 1000000; ++i) {
		bool isPrime = true;
		for (auto &p: primes) {
			if (i % p == 0) {
				isPrime = false;
				break;
			}

			if (p * p > i) break;
		}

		if (isPrime) primes.push_back(i);
	}

	return cout << primes[n - 1], 0;
}
