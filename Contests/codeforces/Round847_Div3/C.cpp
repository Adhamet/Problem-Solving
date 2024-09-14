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

		int p[n][n - 1];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				cin >> p[i][j];
			}
		}
			
		for (int i = 0; i < n; i++) {
			if (i == 0 && p[i + 1][0] && p[i][0] != p[i + 2][0]) {
				cout << p[i + 1][0] << " ";
				for (int j = 0; j < n - 1; j++) cout << p[i][j] << " ";
				break;
			} else if (i == n - 1 && p[i][0] != p[i - 1][0] && p[i][0] != p[i - 2][0]) {
				cout << p[i - 1][0] << " ";
				for (int j = 0; j < n - 1; j++) cout << p[i][j] << " ";
				break;
			} else if (p[i][0] != p[i - 1][0] && p[i][0] != p[i + 1][0]) {
				cout << p[i - 1][0] << " ";
				for (int j = 0; j < n - 1; j++) cout << p[i][j] << " ";
			}
		}
		cout << el;
	}

	return 0;
}
