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

	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	
	int n;
	cin >> n;

	vector<int> cows(n);
	for (auto& c: cows) cin >> c;
	sort(cows.begin(), cows.end());

	int minAns = 0;
	if (cows[n - 2] - cows[0] == n - 2 && cows[n - 1] - cows[n - 2] > 2) {
		minAns = 2;
	} else if (cows[n - 1] - cows[1] == n && cows[1] - cows[0] > 2) {
		minAns = 2;
	} else {
		int range = 0;
		for (int l = 0, r = 0; l < n; l++) {
			while (r < n - 1 && cows[r + 1] - cows[l] <= n - 1) r += 1;
			range = max(range, r - l + 1);
		}

		minAns = n - range;
	}

	cout << minAns << el << max(cows[n - 2] - cows[0], cows[n - 1] - cows[1]) - (n - 2);

	return 0;
}
