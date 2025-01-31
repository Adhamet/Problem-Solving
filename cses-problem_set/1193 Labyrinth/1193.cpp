#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    const int dr[] = {-1, 0, 1, 0};
    const int dc[] = {0, -1, 0, 1};
    const char dir[] = {'U', 'L', 'D', 'R'};
    int n, m;
    cin >> n >> m;
    auto valid = [&](int r, int c) { return r >= 0 && r < n && c >= 0 && c < m; };

    vector<string> grid(n);
    array<int, 2> start, end;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') start = {i, j};
            else if (grid[i][j] == 'B') end = {i, j};
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<char>> dirs(n, vector<char>(m, ' '));
    queue<array<int, 2>> q;
    q.push(start);
    vis[start[0]][start[1]] = true;

    bool found = false;
    while (!q.empty()) {
        int x = q.front()[0], y = q.front()[1];
        q.pop();

        if (x == end[0] && y == end[1]) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dr[i], ny = y + dc[i];
            if (valid(nx, ny) && !vis[nx][ny] && grid[nx][ny] != '#') {
                vis[nx][ny] = true;
                dirs[nx][ny] = dir[i];
                q.push({nx, ny});
            }
        }
    }

    if (!found) return cout << "NO", 0;

    vector<char> path;
    int x = end[0], y = end[1];
    while (x != start[0] || y != start[1]) {
        char currDir = dirs[x][y];
        path.push_back(currDir);
        if (currDir == 'U') x += 1;
        else if (currDir == 'D') x -= 1;
        else if (currDir == 'L') y += 1;
        else if (currDir == 'R') y -= 1;
    }

    reverse(path.begin(), path.end());
    cout << "YES" << el << (int)path.size() << el;
    for (const char& c : path) cout << c;
    return 0;
}
