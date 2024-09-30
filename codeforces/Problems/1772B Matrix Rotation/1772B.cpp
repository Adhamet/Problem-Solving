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
		int a[2][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> a[i][j];
			}
		}

		auto check = [&]() {
			if (a[0][0] < a[0][1] && a[0][0] < a[1][0]) {
				if (a[0][1] < a[1][1] && a[1][0] < a[1][1]) {
					return true;
				}
			}

			return false;
		};

		bool acc = false;
		for (int i = 0; i < 4; i++) {
			if (check()) {
				acc = true;
				break;
			} else {
				swap(a[0][0], a[0][1]);
				swap(a[0][0], a[1][1]);
				swap(a[0][0], a[1][0]);
			}
		}

		cout << (acc ? "YES": "NO") << el;
	}

	return 0;
}
