#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

const int MXN = 2e6;
bitset<MXN+1> dp;

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;	cin >> n;
	vector<bool> isPractical(MXN+1, 0);

	vector<int> primitive;
	for (int x = 1; x <= MXN; ++x) {
		dp.reset();
		dp[0] = 1;

		vector<int> divs;
		for (int d = 1; d * d <= x; ++d) if (x % d == 0) {
			divs.push_back(d);
			if (d * d != x) divs.push_back(x / d);
		}

		for (auto &d: divs) dp |= (dp << d);

		bool prac = true;
		for (int i = 1; i <= x; ++i) if (!dp[i]) {
			prac = false;
			break;
		}

		if (!prac) continue;
		isPractical[x] = true;

		bool prim = true;
		for (auto &d: divs) {
			if (d == 1 || d == x) continue;
			if (isPractical[d] && (d % (x / d)) == 0) {
				prim = false;
				break;
			}
		}

		if (prim) {
			primitive.push_back(x);
			if ((int)primitive.size() == n)
				return cout << x, 0;
		}
	}

	return 0;
}
