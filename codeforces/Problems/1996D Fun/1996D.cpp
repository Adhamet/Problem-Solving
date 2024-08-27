#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 2e5+10;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, x;
		cin >> n >> x;

		int ans = 0;

		for (int a = 1; a <= n; a++) {
			for (int b = 1; a * b <= n; b++) {
				int c = min((n - (a * b)) / (a + b), x - a - b);
				if (c >= 1) ans += c;
			}
		}

		cout << ans << el;
	}

	return 0;
}
