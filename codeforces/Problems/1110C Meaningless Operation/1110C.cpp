#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	unordered_map<i64, i64> sols;
	for (int i = 2; i <= 25; ++i) {
		i64 x = (1LL << i) - 1;
		i64 best = 1;
		for (i64 j = 2; j * j <= x; ++j) {
			if (x % j == 0) {
				best = j;
				break;
			}
		}

		if (best != 1) sols[x] = x / best;
		else sols[x] = 1;
	}

	int q;	cin >> q;
	while (q--) {
		i64 a, x = 0, nxt = 1;	cin >> a;
		while (nxt <= a) ++x, nxt = (1LL << x);

		i64 msk = nxt - 1;
		if (msk == a) cout << sols[a] << el;
		else cout << msk << el;
	}

	return 0;
}

