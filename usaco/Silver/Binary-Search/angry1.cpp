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

	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;

	vector<int> x(n);
	for (auto &i: x) cin >> i;
	sort(x.begin(), x.end());

	auto can = [&](int R) -> bool {
		int range = 2 * R, cowsHit = 1, start = x.front();
		
		for (int i = 1; i < n; i++) {
			if (x[i] - start > range) {
				cowsHit += 1, start = x[i];
				if (cowsHit > k) return false;
			}
		}

		return true;
	};
	
	int l = 0, r = INT_MAX, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;

		if (can(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << el;

	return 0;
}
