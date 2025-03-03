#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

int a, b, c;
vector<int> memo;
int solve(int rem) {
	if (rem == 0) return 0;
	if (rem < 0) return LLONG_MIN;
	if (memo[rem] != -1) return memo[rem];
	memo[rem] = 1 + max({solve(rem - a), solve(rem - b), solve(rem - c)});
	return memo[rem];
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n >> a >> b >> c;
	memo.assign(n + 1, -1);
	solve(n);
	return cout << memo[n], 0;
}
