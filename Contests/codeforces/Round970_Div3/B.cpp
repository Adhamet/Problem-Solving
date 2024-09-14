#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 4e5+5;
/*const int oo = 3e9 + 20;*/

int main() {
	ios_base::sync_with_stdio(2), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		int root = sqrt(n);
		if (root * root != n) {
			cout << "NO" << el;
			continue;
		} else {
			bool isBeautiful = true;
			for (int i = 0; i < n; ++i) {
				int row = i / root;
				int col = i % root;

				if (row == 0 || row == root - 1 || col == 0 || col == root - 1) {
					if (s[i] != '1') {
						isBeautiful = false;
						break;
					}
				} else {
					if (s[i] != '0') {
						isBeautiful = false;
						break;
					}
				}
			}

			if (isBeautiful) cout << "YES" << el;
			else cout << "NO" << el;	
		}
	}

	return 0;
}
