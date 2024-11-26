#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

vector<int> primes;
void sieve(int n) {
	vector<bool> isPrime(n + 1, true);
	isPrime[0] = isPrime[1] = true;
	for (int i = 2; i * i <= n; i++) if (isPrime[i]) {
		for (int j = i * i; j <= n; j += i) isPrime[j] = false;
	}

	for (int i = 2; i <= n; i++) if (isPrime[i]) {
		primes.push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	const int MAXN = 20000000;
	sieve(MAXN);
	vector<pair<int, int>> primepairs;
	for (size_t i = 0; i + 1 < primes.size(); i++) {
		if (primes[i + 1] == primes[i] + 2) primepairs.push_back({primes[i], primes[i + 1]});
	}

	int n;
	while (cin >> n) cout << "(" << primepairs[n - 1].first << ", " << primepairs[n - 1].second << ")" << el;
	return 0;
}
