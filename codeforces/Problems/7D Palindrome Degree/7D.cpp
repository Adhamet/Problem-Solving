#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

static i64 binexp(i64 b, i64 e, i64 m) {
    i64 r = 1;
    b %= m;
    while(e) {
        if (e & 1) r = (r * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return r;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	const i64 P = 79, M = 1e9+7;

	string s;	cin >> s;
	int n = (int)s.size();

	i64 invP = binexp(P, M-2, M);
	vector<i64> powa(n, 0), invpowa(n, 0);
	powa[0] = invpowa[0] = 1;
	for (int i = 0; i < n - 1; ++i) {
		powa[i + 1] = powa[i] * P % M;
		invpowa[i + 1] = invpowa[i] * invP % M;
	}

	vector<i64> hP(n + 1, 0), hS(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		hP[i + 1] = (hP[i] + (s[i] - '0' + 1) * powa[i]) % M;
		hS[i + 1] = (hS[i] + (s[n - i - 1] - '0' + 1) * powa[i]) % M;
	}

	i64 ans = 0;
	vector<i64> remember(n + 1, 0);
	for (int l = 1; l <= n; ++l) {
		i64 lHS1 = hP[l];
		i64 rHS1 = (hS[n] - hS[n - l] + M) % M;
		rHS1 = rHS1 * invpowa[n - l] % M;

		if (lHS1 == rHS1) {
			if (l == 1) remember[l] = 1;
			else remember[l] = remember[l>>1]+1;
			ans += remember[l];
		} else remember[l] = 0;
	}

	return cout << ans, 0;
}
