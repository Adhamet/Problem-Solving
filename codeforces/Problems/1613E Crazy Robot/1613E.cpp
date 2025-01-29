#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    const int dr[] = {-1, 0, 1, 0};
    const int dc[] = {0, -1, 0, 1};
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) cin >> grid[i];

        array<int, 2> lab = {-1, -1};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'L') {
                    lab[0] = i, lab[1] = j;
                    break;
                }
            }
            if (lab[0] != -1) break;
        }

        queue<array<int, 2>> q;
        q.push(lab);

        while (!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dr[i];
                int ny = y + dc[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != '.') {
                    continue;
                }

                int cnt = 0;
                for (int j = 0; j < 4; ++j) {
                    int nnx = nx + dr[j];
                    int nny = ny + dc[j];

                    if (nnx < 0 || nnx >= n || nny < 0 || nny >= m || grid[nnx][nny] == '#') {
                        continue;
                    }

                    if (grid[nnx][nny] != '+' && grid[nnx][nny] != 'L') cnt += 1;
                }

                if (cnt <= 1) {
                    grid[nx][ny] = '+';
                    q.push({nx, ny});
                }
            }
        }

        for (int i = 0; i < n; ++i) cout << grid[i] << el;
    }
    return 0;
}
