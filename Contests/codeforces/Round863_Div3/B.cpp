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

int n;
bool inbounds(int x1, int y1, int x2, int y2) {
	return (x1 >= x2 && x1 <= n - x2) && (y1 == y2 || y1 == n - y2);
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > n/2) x1 = n - x1 + 1;
		if (y1 > n/2) y1 = n - y1 + 1;
		if (x2 > n/2) x2 = n - x2 + 1;
		if (y2 > n/2) y2 = n - y2 + 1;

		ll ans1 = min(x1, y1), ans2 = min(x2, y2);
		cout << abs(ans1 - ans2) << el;
	}

	return 0;
}
