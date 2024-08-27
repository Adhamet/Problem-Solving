#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
const int MOD = 998244353;
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pi> r(m);
	for (auto &i: r) cin >> i.F >> i.S;

	vector<ll> dp(n + 3e5 + 5);
	dp[1] = 1;
	for (int i = 1; i <= n; i++) {
		if (i > 2) dp[i] = (dp[i] + dp[i - 1]) % MOD;

		for (int j = 0; j < m; j++) {
			dp[i + r[j].F] = (dp[i + r[j].F] + dp[i]) % MOD;
			dp[i + r[j].S + 1] = (dp[i + r[j].S + 1] - dp[i] + MOD) % MOD;
		}
	}

	cout << dp[n] << el;

	return 0;
}
