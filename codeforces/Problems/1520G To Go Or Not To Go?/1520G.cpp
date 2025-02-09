#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

const int oo = 1e18 + 10;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, w;
vector<vector<int>> g;

vector<vector<int>> bfs(array<int, 2> start) {
    vector<vector<int>> dist(n, vector<int>(m, oo));
    priority_queue<array<int, 3>> pq;

    dist[start[0]][start[1]] = 0;
    pq.push({0, start[0], start[1]});

    while (!pq.empty()) {
        int cost = -pq.top()[0], x = pq.top()[1], y = pq.top()[2];
        pq.pop();

        if (dist[x][y] < cost) continue;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == -1) continue;

            if (dist[x][y] + w < dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + w;
                pq.push({-dist[nx][ny], nx, ny});
            }
        }
    }

    return dist;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m >> w;
    g.assign(n, vector<int>(m));

    vector<array<int, 2>> portal;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] > 0) portal.push_back({i, j});
        }
    }

    if (g[0][0] == -1 || g[n - 1][m - 1] == -1) return cout << -1, 0;

    auto distS = bfs({0, 0});
    auto distE = bfs({n - 1, m - 1});

    int bestStartPortal = oo;
    int bestEndPortal = oo;
    int ans = oo;

    for (auto &[px, py] : portal) {
        if (distS[px][py] < oo) bestStartPortal = min(bestStartPortal, distS[px][py] + g[px][py]);
        if (distE[px][py] < oo) bestEndPortal = min(bestEndPortal, distE[px][py] + g[px][py]);
    }

    if (distS[n - 1][m - 1] < oo) ans = distS[n - 1][m - 1];
    if (bestStartPortal < oo && bestEndPortal < oo) ans = min(ans, bestStartPortal + bestEndPortal);

    return cout << (ans >= oo? -1: ans), 0;
}

