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
	for (int i = 0; i < n; i++) {
		int x; 
		std::cin >> x;
	}
	
	std::set<int> seenPrimes;
	bool cost0 = false;
	for (int x: a) {
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
		if (cost0) break;
	}
	
	if (cost0) {
		std::cout << 0 << '\n';
		return;
	}
	
	bool cost1 = false;
	for (int x: a) {
		int tmp = x + 1;
		for (int p: primes) {
			if (p * p > tmp) break;
			if (tmp % p == 0) {
				if (seenPrimes.count(p)) {
					cost1 = true;
					break;
				}
				while (tmp % p == 0) tmp /= p;
			}
		}
		if (tmp > 1) {
			if (seenPrimes.count(tmp)) cost1 = true;
		}
		if (cost1) break;
	}
	
	std::cout << (cost1 ? 1: 2) << '\n';
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

