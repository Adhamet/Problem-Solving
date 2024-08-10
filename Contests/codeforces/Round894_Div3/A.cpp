#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> grid(n, vector<char>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        string target = "vika";
        int letter = 0;

        for (int j = 0; j < m && letter < 4; j++) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == target[letter]) {
                    letter++;
                    break;
                }
            }
        }

        if (letter == 4) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
