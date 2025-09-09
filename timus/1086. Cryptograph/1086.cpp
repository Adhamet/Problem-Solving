#include <bits/stdc++.h>
#define i64 int64_t

int32_t main() {
	const int MXN = 1e7;

	int idx = 0;
	std::vector<bool> isPrime(MXN, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= MXN; ++i) if (isPrime[i]) {
		for (int j = i * i; j <= MXN; j += i)
			isPrime[j] = false;
	}

	std::vector<int> primes;
	for (int x = 2; x <= MXN; ++x) if (isPrime[x])
		primes.push_back(x);

	int k;	scanf("%d", &k);
	while (k--) {
		int idx;
		scanf("%d", &idx);
		printf("%d\n", primes[idx - 1]);
	}

	return 0;
}
