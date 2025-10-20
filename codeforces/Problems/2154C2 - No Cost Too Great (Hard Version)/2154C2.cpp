#include <bits/stdc++.h>
using i64 = long long;

std::vector<int> primes;

void generatePrimes(int n) {
	std::vector<bool> isPrime(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) std::cin >> a[i];
	std::vector<i64> b(n);
	for (int i = 0; i < n; i++) std::cin >> b[i];
	
	std::vector<int> ord(n);
	std::iota(ord.begin(), ord.end(), 0);
	std::sort(ord.begin(), ord.end(), [&](int i, int j) { return b[i] < b[j]; });
	
	i64 ans = b[ord[0]] + b[ord[1]];
	
	std::set<int> seenPrimes;
	bool cost0 = false;
	for (int i = 0; i < n && !cost0; i++) {
		int x = a[ord[i]];
		int tmp = x;
		for (int p : primes) {
			if (p * p > tmp) break;
			if (tmp % p == 0) {
				if (seenPrimes.count(p)) {
					cost0 = true;
					break;
				}
				seenPrimes.insert(p);
				while (tmp % p == 0) tmp /= p;
			}
		}
		if (tmp > 1) {
			if (seenPrimes.count(tmp)) cost0 = true;
			seenPrimes.insert(tmp);
		}
	}
	
	if (cost0) {
		std::cout << 0 << '\n';
		return;
	}
	
	bool cost1 = false;
	for (int i = 0; i < n && !cost1; i++) {
		int x = a[ord[i]];
		int tmp = x + 1;
		for (int p: primes) {
			if (p * p > tmp) break;
			if (tmp % p == 0) {
				if (seenPrimes.count(p)) {
					ans = std::min(ans, b[ord[i]]);
					cost1 = true;
					break;
				}
				while (tmp % p == 0) tmp /= p;
			}
		}
		if (tmp > 1) {
			if (seenPrimes.count(tmp)) {
				ans = std::min(ans, b[ord[i]]);
				cost1 = true;
			}
		}
	}
	
	std::set<int> targetPrimes;
	for (int i = 1; i < n; i++) {
		int tmp = a[ord[i]];
		for (int p : primes) {
			if (p * p > tmp) break;
			if (tmp % p == 0) {
				targetPrimes.insert(p);
				while (tmp % p == 0) tmp /= p;
			}
		}
		if (tmp > 1) targetPrimes.insert(tmp);
	}
	
	for (int p: targetPrimes) {
		int rem = a[ord[0]] % p;
		if (rem != 0) {
			int ops = p - rem;
			ans = std::min(ans, (i64)ops * b[ord[0]]);
		}
	}
	
	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	generatePrimes(500);
	
	int t;	std::cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}
