#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using lld = long double;
#define int long long
#define el '\n'

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	lld n;
	cin >> n;

	auto isPerfSq = [&](lld k) {
		int kk = (int)sqrt(k);
		return kk * kk == k;
	};

	auto countDigit = [&](int k) {
		string kk = to_string(k);
		int cnt = 0;
		for (int i = 0; i < kk.length(); ++i) cnt += (kk[i]-'0');
		return cnt;
	};

	for (lld sx = 1; sx < 82; ++sx) {
		lld underRoot = sx*sx + 4*n;
		if (isPerfSq(underRoot)) {
			int x = -sx + sqrt(underRoot);
			if (x % 2 == 0 && countDigit(x/2) == sx) {
				return cout << x/2, 0;
			}
		}
	}

	return cout << -1, 0;
}
