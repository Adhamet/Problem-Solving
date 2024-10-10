#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;

const int N = 2500;	
int n, pref[N + 1][N + 1];
pi pts[N];

int rsum(int x1, int y1, int x2, int y2) {
	return pref[x2 + 1][y2 + 1] - pref[x2 + 1][y1] - pref[x1][y2 + 1] + pref[x1][y1];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> pts[i].F >> pts[i].S;

	sort(pts, pts + n);
	for (int i = 0; i < n; i++) pts[i].F = i + 1;
	sort(pts, pts + n, [](pi &a, pi &b) { return a.S < b.S; });
	for (int i = 0; i < n; i++) pts[i].S = i + 1;

	for (int i = 0; i < n; i++) pref[pts[i].F][pts[i].S] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int x1 = min(pts[i].F, pts[j].F) - 1;
			int x2 = max(pts[i].F, pts[j].F) - 1;

			ll lo = rsum(0, i, x1, j), hi = rsum(x2, i, n - 1, j);
			ans += lo * hi;
		}
	}
	cout << ans + 1 << el;

	return 0;
}
