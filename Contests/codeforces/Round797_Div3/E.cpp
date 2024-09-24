#include <bits/stdc++.h>
using namespace std;

#define el '\n'

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		long long ans = 0;
		vector<int> a(n), rem;
		for (auto &i: a) cin >> i, ans += i / k;
		for (auto &i: a) rem.push_back(i % k);
		sort(rem.begin(), rem.end());

		int l = 0, r = n - 1;
		while (l < r) {
			if (rem[l] + rem[r] >= k) ans += 1, l += 1, r -= 1;
			else l += 1;
		}

		cout << ans << el;
	}

	return 0;
}
