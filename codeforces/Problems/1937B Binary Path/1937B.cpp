#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'

const int N = 1000010;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		char grid[3][N];
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> grid[i][j];
			}
		}

		int mxDown = n, mnDown = 1;

		for (int i = n; i >= 2; i--) {
			if (grid[2][i - 1] == '0' && grid[1][i] == '1') {
				mxDown = i - 1;
			}
		}

		for (int i = 1; i < mxDown; i++) {
			if (grid[1][i + 1] == '0' && grid[2][i] == '1') {
				mnDown = i + 1;
			}
		}

		for (int i = 1; i <= mxDown; i++) cout << grid[1][i];
		for (int i = mxDown; i <= n; i++) cout << grid[2][i];
		
		cout << el << mxDown - mnDown + 1 << el;
	}

	return 0;
}
