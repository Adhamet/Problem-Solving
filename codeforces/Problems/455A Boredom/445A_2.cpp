#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int MAXN = 1e5+5;
int n;
vector<int> dp(MAXN, -1), freq(MAXN, 0);

int recurse(int x) {
	if (x > 1e5) return 0;

	int &ret = dp[x];
	if (~ret) return ret;
	ret = 0;

	return ret = max(recurse(x + 1), freq[x] * x + recurse(x + 2));
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0, tmpX; i < n; ++i) cin >> tmpX, ++freq[tmpX];
	return cout << recurse(0), 0;
}
