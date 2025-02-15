#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int oo = 1e18;
const int dx[] = {1, 2, -1, -2, 1, 2, -1, -2};
const int dy[] = {2, 1, 2, 1, -2, -1, -2, -1};

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        if (a == c && b == d) {
            cout << 0 << el;
            continue;
        }

        vector<vector<int>> dist(8, vector<int>(8, oo));
        dist[a][b] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, a, b});

        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();

            if (x == c && y == d) break;
            if (cost > dist[x][y]) continue;

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;

                int ncost = cost + (x * nx) + (y * ny);
                if (ncost < dist[nx][ny]) {
                    dist[nx][ny] = ncost;
                    pq.push({ncost, nx, ny});
                }
            }
        }

        cout << (dist[c][d] == oo ? -1 : dist[c][d]) << el;
    }

    return 0;
}