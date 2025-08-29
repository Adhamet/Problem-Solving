#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	constexpr int MXN = 4e4+5, MOD = 1e9+7;

	vector<int> nums;
	for (int a = 1; a <= 9; ++a) nums.push_back(a);
	for (int a = 1; a <= 9; ++a) nums.push_back(10*a + a);
	for (int a = 1; a <= 9; ++a)
		for (int b = 0; b <= 9; ++b)
			nums.push_back(100*a + 10*b + a);
	for (int a = 1; a <= 9; ++a)
		for (int b = 0; b <= 9; ++b)
			nums.push_back(1000*a + 100*b + 10*b + a);
	for (int a = 1; a <= 4; ++a)
		for (int b = 0; b <= 9; ++b)
			for (int c = 0; c <= 9; ++c)
				nums.push_back(10000*a + 1000*b + 100*c + 10*b + a);	

	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	vector<int> dp(MXN, 0);		dp[0] = 1;
	for (int coin: nums) {
		for (int rem = coin; rem < MXN; ++rem) {
			dp[rem] += dp[rem - coin];
			if (dp[rem] >= MOD) dp[rem] -= MOD;
		}
	}

	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		cout << dp[x] << '\n';
	}

	return 0;
}

