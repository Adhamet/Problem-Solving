#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m, cnt;
vector<vector<bool>> vis;
vector<vector<char>> adjmtx;
bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y) {
    if (!valid(x, y) || vis[x][y] || adjmtx[x][y] == '~') return;
    cnt += 1, vis[x][y] = true;
    for (int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vis.assign(n, vector<bool>(m, false));
        adjmtx.assign(n, vector<char>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> adjmtx[i][j];
            }
        }

	int islands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (adjmtx[i][j] == '#' && !vis[i][j]) {
                    cnt = 0;
                    dfs(i, j);
                    islands += (cnt * cnt);
                }
            }
        }

        if (islands == 0) {
            cout << 0 << el;
        } else {
			int cells = n * m;
            int gcd = __gcd(islands, cells);
            int numerator = islands / gcd;
            int denominator = cells / gcd;
            if (denominator == 1) cout << numerator << el;
            else cout << numerator << " / " << denominator << el;
        }
    }

    return 0;
}
