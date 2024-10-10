#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<int> friends(n), speed(n);
	for (auto &f: friends) cin >> f;
	for (auto &s: speed) cin >> s;

	auto can = [&](double mid) {
		double right = 1e9, left = -1e9;
		for (int i = 0; i < n; i++) {
			right = min(right, friends[i] + mid * speed[i]);
			left = max(left, friends[i] - mid * speed[i]);
		}
		
		return right >= left;
	};
	
	double ans = 0;
	double l = 0, r = 1e9;
	for(int i = 0; i < 1000; i++) {
		double mid = (l + r) / 2;
		if (can(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}

	cout << fixed << setprecision(9) << ans << el;
	return 0;
}
