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

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> grid(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char c;
				cin >> c;
				grid[i][j] = int(c - '0');
			}
		}

		ll ans = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = i; j < n - i - 1; j++) {
				ll one = 0, zero = 0;

				if (grid[i][j] == 0) zero++;
				else one++;
				if (grid[j][n - i - 1] == 0) zero++;
				else one++;
				if (grid[n - i - 1][n - j - 1] == 0) zero++;
				else one++;
				if (grid[n - j - 1][i] == 0) zero++;
				else one++;

				ans += min(4 - one, 4 - zero);
			}
		}
		cout << ans << el;
	}

	return 0;
}
