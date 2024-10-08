#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define el '\n'

using pi = pair<int, int>;

const int oo = 1e9;
struct pt {
    int x, y;
};

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
map<pi, bool> valid;
map<pi, bool> vis;

int bfs(int startX, int startY, int endX, int endY) {
    queue<pair<pi, int>> q;
    q.push({{startX, startY}, 0});

    vis[{startX, startY}] = true;
    if (!valid[{startX, startY}]) return -1;

    while (q.size()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();

        if (x == endX && y == endY) return z;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= 1e9 && ny >= 1 && ny <= 1e9 && valid[{nx, ny}] && !vis[{nx, ny}]) {
                vis[{nx, ny}] = true;
                q.push({{nx, ny}, z + 1});
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    pt from, to;
    cin >> from.x >> from.y >> to.x >> to.y;

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int j = a; j <= b; j++) {
            valid[{r, j}] = true;
        }
    }

    cout << bfs(from.x, from.y, to.x, to.y) << el;
    return 0;
}
