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
    array<int, 2> start;
    vector<array<int, 2>> monsters;

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') start = {i,j};
            else if (grid[i][j] == 'M') monsters.push_back({i,j});
        }
    }

    vector<vector<int>> distMs(n, vector<int>(m, -1));
    queue<array<int, 2>> q;
    for (auto xy: monsters) {
        distMs[xy[0]][xy[1]] = 0;
        q.push(xy);
    }

    while (!q.empty()) {
        int x = q.front()[0], y = q.front()[1];
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dr[i], ny = y + dc[i];
            if (valid(nx, ny) && grid[nx][ny] != '#' && distMs[nx][ny] == -1) {
                distMs[nx][ny] = distMs[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }

    vector<vector<int>> distA(n, vector<int>(m, -1));
    vector<vector<char>> dirs(n, vector<char>(m, ' '));
    queue<array<int, 2>> qq;
    distA[start[0]][start[1]] = 0;
    qq.push(start);

    while (!qq.empty()) {
        int x = qq.front()[0], y = qq.front()[1];
        qq.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dr[i], ny = y + dc[i];
            if (valid(nx, ny) && grid[nx][ny] != '#' && distA[nx][ny] == -1) {
                distA[nx][ny] = distA[x][y] + 1;
                dirs[nx][ny] = dir[i];
                qq.push({nx,ny});
            }
        }
    }

    int steps = INT_MAX;
    array<int, 2> exit = {-1,-1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                if (grid[i][j] != '#' && distA[i][j] != -1) {
                    bool ok = true;
                    if (!monsters.empty()) {
                        if (distMs[i][j] != -1 && distMs[i][j] <= distA[i][j]) ok = false;
                    }

                    if (ok && distA[i][j] < steps) {
                        steps = distA[i][j];
                        exit = {i,j};
                    }
                }
            }
        }
    }

    if (exit[0] == -1) return cout << "NO", 0;

    vector<char> path;
    int x = exit[0], y = exit[1];
    while (x != start[0] || y != start[1]) {
        char currDir = dirs[x][y];
        path.push_back(currDir);
        for (int i = 0; i < 4; ++i) {
            if (dir[i] == currDir) {
                x -= dr[i], y -= dc[i];
                break;
            }
        }
    }

    reverse(path.begin(), path.end());
    cout << "YES" << el << (int)path.size() << el;
    for (const char& direction: path) cout << direction;
    return 0;
}
