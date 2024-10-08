#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'

using pi = pair<int, int>;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    string tmp;
    cin.ignore();
    getline(cin, tmp);

    while (t--) {
        vector<string> adjMtrx;
        while (true) {
            getline(cin, tmp);
            if (tmp == "") break;
            else adjMtrx.push_back(tmp);
        }

        size_t n = adjMtrx.size(), m = adjMtrx[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));

        auto valid = [&](int x, int y) -> bool { return (x >= 0 && x < n && y >= 0 && y < m); };
        auto bfs = [&](int startX, int startY) -> int {
            queue<pi> q;
            q.push({startX, startY});
            vis[startX][startY] = true;

            int cnt = 1;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (!valid(nx, ny) || vis[nx][ny] || adjMtrx[nx][ny] == '0') {
                        continue;
                    }

                    cnt += 1;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }

            return cnt;
        };

        int maxBlobSize = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                if (!vis[i][j] && adjMtrx[i][j] == '1') {
                    maxBlobSize = max(maxBlobSize, bfs(int(i), int(j)));
                }
            }
        }

        cout << maxBlobSize << el;
        if (t) cout << el;
    }

    return 0;
}
