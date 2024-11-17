#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

vector<bool> isPrime;
vector<int> primes;
void sieve(int n) {
	isPrime.assign(n + 1, true);
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i * i <= n; ++i) if (isPrime[i]) {
		for (int j = i * i; j <= n; j += i) isPrime[j] = false;
	}

	for (int i = 2; i <= n; ++i) if (isPrime[i]) {
		primes.push_back(i);
	}
}

bool findSum(int sum, int &p1, int &p2) {
	for (const int &prime: primes) {
		if (prime >= sum) break;
		if (sum - prime > 1 && isPrime[sum - prime]) {
			p1 = prime, p2 = sum - prime;
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
    const int MAXN = 10000000;
	sieve(MAXN);
	int n;
	while (cin >> n) {
		if (n < 8) {
			cout << "Impossible." << el;
		} else {
			int p1, p2, p3, p4;
			bool found = false;

			if (findSum(n - 4, p3, p4)) {
				p1 = 2, p2 = 2;
				found = true;
			} else if (n % 2 == 1 && findSum(n - 5, p3, p4)) {
				p1 = 2, p2 = 3;
				found = true;
			} else if (n % 2 == 0 && findSum(n - 6, p3, p4)) {
				p1 = 3, p2 = 3;
				found = true;
			}

			if (found) {
				cout << p1 << " " << p2 << " " << p3 << " " << p4 << el;
			} else cout << "Impossible." << el;
			cout.flush();
		}
	}

	return 0;
}

