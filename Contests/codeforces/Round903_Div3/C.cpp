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

        vector<vector<char>> vec(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> vec[i][j];
            }
        }

		ll op = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = i; j < n - i - 1; j++) {
				int a = vec[i][j];
				int b = vec[j][n - i - 1];
				int c = vec[n - i - 1][n - j - 1];
				int d = vec[n - j - 1][i];

				int mx = max({a, b, c, d});

				op += (mx - a) + (mx - b) + (mx - c) + (mx - d); 
			}
		}

		cout << op << '\n';
    }

    return 0;
}

