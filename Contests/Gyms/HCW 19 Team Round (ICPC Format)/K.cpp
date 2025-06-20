#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

const int MXN = 1e4+5, MOD = 1e9+9;
int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	auto sieve = []() {
		vector<int> v, isPrime(MXN, 0);
		isPrime[0] = isPrime[1] = 1;
		for (i64 i = 2; i < MXN; i++)
			if (!isPrime[i])
				for (i64 j = i * i; j < MXN; j += i) isPrime[j] = 1;
		for (int i = 0; i < MXN; i++)
			if (!isPrime[i]) v.push_back(i);
		return v;
	};

	auto binexp = [](i64 a, i64 b) {
		i64 res = 1, y = a;
		while (b > 0) {
			if (b & 1) res = (res * y) % MOD;
			y = (y * y) % MOD;
			b >>= 1;
		}
		return res;
	};

	vector<int> primes = sieve();
	int n; cin >> n;
	int ans[n+1], last = 1;

	for (int i = n - 1; i >= 1; i -= 2) {
		cout << "? " << i << " " << n << el;
		cout.flush();
		int curr; cin >> curr;
		int val = (1LL * curr * binexp(last, MOD-2)) % MOD;
		last = curr;

		for (int p: primes) if (val % p == 0) {
			ans[i] = min(val / p, p);
			ans[i + 1] = max(val / p, p);
			break;
		}
	}

	if (n & 1) {
		cout << "? " << 1 << " " << n << el;
		cout.flush();
		int curr; cin >> curr;
		ans[1] = (1LL * curr * binexp(last, MOD - 2)) % MOD;
	}

	cout << "! ";
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}
