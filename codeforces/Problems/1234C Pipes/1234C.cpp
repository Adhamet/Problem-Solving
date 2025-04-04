#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int tc;
    scanf("%d", &tc);

    while (tc--) {
        int32_t n;
        scanf("%d", &n);

        vector<vector<char>> grid(2, vector<char>(n));
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < n; ++j)
                scanf(" %c", &grid[i][j]);

        vector<vector<array<bool, 2>>> vis(2, vector<array<bool, 2>>(n, {false, false}));
        queue<tuple<int, int, int>> q;

        q.push({0, 0, 0});
        vis[0][0][0] = true;

        bool acc = false;
        while (!q.empty()) {
            auto [x, y, dir] = q.front();
            q.pop();

            if (x == 1 && y == n - 1) {
                int pipe = grid[x][y] - '0';
                if ((pipe <= 2 && dir == 0) || (pipe >= 3 && dir == 1)) {
                    acc = true;
                    break;
                }
            }

            int pipe = grid[x][y] - '0';

            if (pipe <= 2) {
                if (dir == 0) { // coming from left, can go right
                    int ny = y + 1;
                    if (ny < n && !vis[x][ny][0]) {
                        vis[x][ny][0] = true;
                        q.push({x, ny, 0});
                    }
                }
            } else {
                if (dir == 0) { // coming from left, switch rows
                    int nx = 1 - x;
                    if (!vis[nx][y][1]) {
                        vis[nx][y][1] = true;
                        q.push({nx, y, 1});
                    }
                } else { // coming from vertical, move right
                    int ny = y + 1;
                    if (ny < n && !vis[x][ny][0]) {
                        vis[x][ny][0] = true;
                        q.push({x, ny, 0});
                    }
                }
            }
        }

        printf(acc ? "YES\n" : "NO\n");
    }

    return 0;
}
