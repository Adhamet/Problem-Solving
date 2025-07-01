#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int N = 100005;
	bool isPrime[N];
	memset(isPrime, 1, sizeof isPrime);
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i * i < N; i++) if (isPrime[i])
		for (int j = i * i; j < N; j += i)
			isPrime[j] = 0;
	vector<int> primes;
	for (int i = 2; i < N; ++i) if (isPrime[i])
		primes.push_back(i);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> a(n + 1);
		iota(a.begin(), a.end(), 0);
		for (int multi = 2; multi <= n; ++multi) {
			for (auto& p: primes) {
				if (p > (n / multi)) break;
				if (__gcd(a[p], multi * p) > 1 && __gcd(p, a[multi * p]) > 1)
					swap(a[p], a[multi * p]);
			}
		}

		for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
		cout << el;
	}

	return 0;
}

