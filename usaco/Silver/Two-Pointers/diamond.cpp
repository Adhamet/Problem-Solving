#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;

	vector<int> diamonds(n);
	for (int &diamond: diamonds) cin >> diamond;
	sort(diamonds.begin(), diamonds.end());

	vector<int> amountsAboveI(n), amountsBelowI(n);

	int l = 0, r = 0;
	while (r < n) {
		if (diamonds[r] - diamonds[l] <= k) {
			amountsAboveI[l] = r - l + 1, amountsBelowI[r] = r - l + 1;
			r += 1;
		} else l += 1;
	}

	int ans = 0, maxBelow = 0;
	for (int i = 1; i < n; i++) {
		maxBelow = max(maxBelow, amountsBelowI[i - 1]);
		ans = max(ans, maxBelow + amountsAboveI[i]);
	}
	cout << ans;

	return 0;
}
