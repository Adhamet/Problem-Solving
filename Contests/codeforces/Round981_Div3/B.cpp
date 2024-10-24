#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define fst first
#define scd second
#define el '\n'
#define MOD 1000000007

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int MAXN = 20 + 5;*/
/*const int oo = 1e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int mtx[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mtx[i][j];
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mtx[i][j] < 0) {
					int mn = mtx[i][j];
					int x = i + 1, y = j + 1;
					while (x < n && y < n) {
						mn = min(mn, mtx[x][y]);
						x += 1, y += 1;
					}

					ans += abs(mn);

					x = i, y = j;
					while (x < n && y < n) {
						mtx[x][y] += abs(mn);
						x += 1, y += 1;
					}
				}
			}
		}

		cout << ans << el;
	}

	return 0;
}
