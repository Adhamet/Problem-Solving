#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m, cnt;
vector<vector<bool>> vis;
vector<vector<char>> adjmtx;
vector<vector<int>> component;
unordered_map<int, int> pictures;
bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y, int comp) {
    vis[x][y] = true;
    component[x][y] = comp;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny)) {
            if (adjmtx[nx][ny] == '*') cnt += 1;
            else if (!vis[nx][ny] && adjmtx[nx][ny] == '.') dfs(nx, ny, comp);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int k;
    cin >> n >> m >> k;
    vis.assign(n, vector<bool>(m, false));
    adjmtx.assign(n, vector<char>(m));
    component.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adjmtx[i][j];
        }
    }

    int comp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && adjmtx[i][j] == '.') {
                cnt = 0;
                dfs(i, j, comp);
                pictures[comp] = cnt;
                comp++;
            }
        }
    }

    while (k--) {
        int x, y;
        cin >> x >> y;
        x -= 1, y -= 1;
        cout << pictures[component[x][y]] << el;
    }

    return 0;
}

