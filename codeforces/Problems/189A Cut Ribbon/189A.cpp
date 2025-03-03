#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int n, a, b, c, ans = 0;
vector<int> dp;
void solve(int sum, int cnt) {
	if (sum + a <= n && dp[sum + a] < cnt + 1) {
		dp[sum + a] = cnt + 1;
		solve(sum + a, cnt + 1);
	}

	if (sum + b <= n && dp[sum + b] < cnt + 1) {
		dp[sum + b] = cnt + 1;
		solve(sum + b, cnt + 1);
	}

	if (sum + c <= n && dp[sum + c] < cnt + 1) {
		dp[sum + c] = cnt + 1;
		solve(sum + c, cnt + 1);
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> a >> b >> c;
	dp.assign(n + 5, 0);
	dp[0] = 0;
	solve(0, 0);
	cout << dp[n];
}
