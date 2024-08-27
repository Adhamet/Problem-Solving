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
		int n, q;
		string s[2];

		cin >> n >> q >> s[0] >> s[1];

		int pref[2][26][n + 1];

		for (auto t: {0, 1}) {
			for (int c = 0; c < 26; c++) {
				for (int i = 0; i < n; i++) {
					pref[t][c][i + 1] = pref[t][c][i] + (s[t][i] == c + 'a');
				}
			}
		}

		while (q--) {
			int l, r;
			cin >> l >> r;

			int ans = 0;
			for (int c = 0; c < 26; c++) {
				int num1 = pref[0][c][r] - pref[0][c][l - 1];
				int num2 = pref[1][c][r] - pref[1][c][l - 1];

				ans += abs(num1 - num2);
			}

			cout << ans / 2 << el;
		}
	}

	return 0;
}
