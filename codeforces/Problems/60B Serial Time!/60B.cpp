#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    const int dr[] = {-1, 0, 1, 0};
    const int dc[] = {0, -1, 0, 1};
    const int dk[] = {-1, 1};
    int k, n, m;
    cin >> k >> n >> m;
    cin.ignore();

    auto valid2d = [&](int r, int c) { return r >= 0 && r < n && c >= 0 && c < m; };
    auto valid3d = [&](int kk) { return kk >= 0 && kk < k; };

    vector<vector<vector<bool>>> vis(k, vector<vector<bool>>(n, vector<bool>(m)));
    vector<vector<string>> plate(k, vector<string>(n));

    string line;
    vector<string> layers;
    while ((int)layers.size() < k * n && getline(cin, line)) {
        if (!line.empty()) layers.push_back(line);
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            plate[i][j] = layers[i * n + j];
        }
    }

    array<int, 2> start;
    cin >> start[0] >> start[1];
    start[0]--, start[1]--;

    queue<array<int, 3>> q;
    q.push({0, start[0], start[1]});
    vis[0][start[0]][start[1]] = true;

    int minutes = 0;
    while (!q.empty()) {
        int kk = q.front()[0];
        int x = q.front()[1];
        int y = q.front()[2];
        q.pop();

        minutes++;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dr[i];
            int ny = y + dc[i];
            if (valid2d(nx, ny) && !vis[kk][nx][ny] && plate[kk][nx][ny] != '#') {
                vis[kk][nx][ny] = true;
                q.push({kk, nx, ny});
            }
        }

        for (int i = 0; i < 2; ++i) {
            int nkk = kk + dk[i];
            if (valid3d(nkk) && !vis[nkk][x][y] && plate[nkk][x][y] != '#') {
                vis[nkk][x][y] = true;
                q.push({nkk, x, y});
            }
        }
    }

    return cout << minutes, 0;
}
