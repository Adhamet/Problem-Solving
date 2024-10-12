#include <bits/stdc++.h>
using namespace std;

#define el '\n'
using pi = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};
	auto valid = [&](int x, int y, int n, int m) { 
		return x >= 0 && x < n && y >= 0 && y < m; 
	};

	int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        bool vis[n][m];
        memset(vis, false, sizeof vis);

        char grid[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'B') {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (valid(nx, ny, n, m) && grid[nx][ny] == '.') {
                            grid[nx][ny] = '#';
                        }
                    }
                }
            }
        }

        queue<pi> q;
        if (grid[n - 1][m - 1] != '#') {
            q.push({n - 1, m - 1});
            vis[n - 1][m - 1] = true;
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if (valid(nx, ny, n, m) && !vis[nx][ny] && grid[nx][ny] != '#') {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        bool acc = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((grid[i][j] == 'G' && !vis[i][j]) || (grid[i][j] == 'B' && vis[i][j])) {
                    acc = false;
                    break;
                }
            }
        }

        cout << (acc ? "Yes" : "No") << el;
    }

    return 0;
}
