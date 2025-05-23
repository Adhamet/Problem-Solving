#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const int N = 1e7 + 1;
	vector<bool> isPrime(N, true);
	vector<int> ans(N, 0);

	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < N; ++i) {
		if (isPrime[i]) {
			for (int j = i * i; j < N; j += i)
				isPrime[j] = false;
		}
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 2; i * j < N; ++j) {
			if (isPrime[j]) ans[i*j]++;
		}
	}

	for (int i = 1; i < N; ++i) ans[i] += ans[i - 1];

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << ans[n] << el;
	}

	return 0;
}

