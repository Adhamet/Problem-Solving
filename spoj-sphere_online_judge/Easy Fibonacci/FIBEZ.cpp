#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int maxinput = 6e5+5;
const int mod =	1e8+7;
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	vector<int> dp(maxinput+10);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= maxinput; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		x -= 1;
		cout << dp[x] << el;
	}

	return 0;
}
