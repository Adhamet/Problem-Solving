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

	// freopen("angry.in", "r", stdin);
	// freopen("angry.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;

	vector<pi> poss(m);
	for (auto &pr: poss) cin >> pr.first >> pr.second;
	
	// 11100000, the idea is to put the cows with curr D distances apart (OR MORE)
	// and see the maximum D that puts all the cows in place. (Last True)
	auto can = [&](int D) -> bool {
		
	};

	// finding best D
	int l = 0, r = INT_MAX, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;

		if (can(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << el;  

	return 0;
}
