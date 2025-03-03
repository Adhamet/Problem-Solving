#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int n, a, b, c;
vector<int> memo;
int solve(int sum) {
	if (sum == n) return 0;
	if (sum > n) return LLONG_MIN;
	if (memo[sum] != -1) return memo[sum];
	memo[sum] = 1 + max({solve(sum + a), solve(sum + b), solve(sum + c)});
	return memo[sum];
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> a >> b >> c;
	memo.assign(n + 5, -1);
	solve(0);
	return cout << memo[0], 0;
}
