#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int MAXN = 1e5 + 10;
	vector<int> prime;	prime.push_back(2);
	bitset<MAXN/2> isPrime;		isPrime.set();
	for (int i = 3; i * i < MAXN; i += 2) if (isPrime[i>>1])
		for (int j = i * i; j < MAXN; j += (2 * i)) isPrime[j>>1] = 0;
	for (int i = 3; i < MAXN; i += 2) if (isPrime[i>>1]) prime.push_back(i);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> perm(n+1);
		iota(perm.begin(), perm.end(), 0);
	
		for (int mlt = 2; mlt <= n; ++mlt) {
			for (auto &p: prime) {
				if (mlt * p > n) break;
				if (__gcd(p, perm[mlt*p]) > 1 && __gcd(mlt*p, perm[p]) > 1)
					swap(perm[p], perm[mlt*p]);
			}
		}

		for (int i = 1; i <= n; ++i) cout << perm[i] << ' ';
		cout << el;
	}

	return 0;
}
