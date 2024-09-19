#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 2005;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    char grid[N][N];
	vector<vector<int>> x(n + 1, vector<int>(m + 1)), y(n + 1, vector<int>(m + 1)), z(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            x[i][j] = (grid[i][j] == '1') - x[i - 1][j - 1] + x[i - 1][j] + x[i][j - 1];
            y[i][j] = (grid[i - 1][j] == '1' && grid[i][j] == '1') - y[i - 1][j - 1] + y[i][j - 1] + y[i - 1][j];
            z[i][j] = (grid[i][j - 1] == '1' && grid[i][j] == '1') - z[i - 1][j - 1] + z[i][j - 1] + z[i - 1][j];
        }
    }

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int blues = x[c][d] - x[a - 1][d] - x[c][b - 1] + x[a - 1][b - 1];
        int col = y[c][d] - y[a][d] - y[c][b - 1] + y[a][b - 1];
        int row = z[c][d] - z[a - 1][d] - z[c][b] + z[a - 1][b];

        cout << blues - col - row << el;
    }

    return 0;
}

