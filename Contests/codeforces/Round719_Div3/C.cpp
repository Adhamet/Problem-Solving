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

		if (n == 1) {
			cout << 1 << el;
			continue;
		}

		if (n == 2) {
			cout << -1 << el;
			continue;
		}

		vector<vector<int>> ans(n, vector<int>(n));
		int num = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if ((i + j) % 2 == 0) {
					ans[i][j] = num++;
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if ((i + j) % 2 != 0) {
					ans[i][j] = num++;
				}
			}
		}

		for (auto vec: ans) {
			for (auto ele: vec) {
				cout << ele << " ";
			}
			cout << el;
		}
	}

	return 0;
}
