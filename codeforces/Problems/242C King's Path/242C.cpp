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
map<pi, int> dist;
map<pi, bool> valid;

void bfs(int startX, int startY) {
    queue<pi> q;
    q.push({startX, startY});

    if (valid[{startX, startY}]) dist[{startX, startY}] = 0;
    else return;

    while (q.size()) {
        int x = q.front().first;
        int y= q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (valid[{nx, ny}] && dist[{nx, ny}] > dist[{x, y}] + 1) {
                dist[{nx, ny}] = dist[{x, y}] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    pt from, to;
    cin >> from.x >> from.y >> to.x >> to.y;

    dist[{to.x, to.y}] = oo;

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int j = a; j <= b; j++) {
            valid[{r, j}] = 1;
            dist[{r, j}] = oo;
        }
    }

    bfs(from.x, from.y);
    
    cout << (dist[{to.x, to.y}] < 1e9 ? dist[{to.x, to.y}]: -1) << el;
    return 0;
}
