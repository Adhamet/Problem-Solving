#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 105;
const int oo = 1e9;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, m;
char grid[N][N];
int dist[N][N][2];
void bfs(pi start) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 2; k++) {
				dist[i][j][k] = oo;
			}
		}
	}

	queue<pair<pi, int>> q;
	q.push({{start.first, start.second}, 0});
	dist[start.first][start.second][0] = 0;

	int ans = -2;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		if (x == 1 || x == n || y == 1 || y == m) {
			ans = dist[x][y][z];
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z;

			if (grid[nx][ny] == 'O') nz = 1;
			else if (grid[nx][ny] == 'C') nz = 0;

			if (dist[nx][ny][nz] > dist[x][y][z] + 1 && !(grid[nx][ny] == 'W' || (grid[nx][ny] == 'D' && z == 0))) {
				q.push({{nx, ny}, nz});
				dist[nx][ny][nz] = dist[x][y][z] + 1;
			}
		}
	}

	cout << ans + 1 << el;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	while (true) {
		cin >> n >> m;
		if (n == -1) break;

		pi start;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 'H') start.first = i, start.second = j;
			}
		}

		bfs(start);
	}	

	return 0;
}
