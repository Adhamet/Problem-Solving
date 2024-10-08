#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

/*const int N = 20 + 5;*/
/*const int oo = 1e9 + 20;*/
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

	bool vis[n][m];
    vector<string> grid(n);
    memset(vis, 0, sizeof vis);

    pi last;
	int path = 0;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                path++;
                last = {i, j};
            }
        }
    }

    int cnt = path - k;

    queue<pi> q;
    q.push(last);

	int visited = 1;
    vis[last.first][last.second] = true;
    while (!q.empty() && visited < cnt) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == '.') {
                vis[nx][ny] = true;
                q.push({nx, ny});
                visited++;

                if (visited == cnt) break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) grid[i][j] = 'X';
        }
    }

    for (int i = 0; i < n; i++) cout << grid[i] << el;
    return 0;
}
