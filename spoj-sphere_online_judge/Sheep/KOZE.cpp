#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
bool escape;
int n, m, sheepCnt, wolvCnt;
vector<vector<bool>> vis;
vector<vector<char>> adjmtx;
bool valid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y) {
	if (!valid(x, y) || vis[x][y] || adjmtx[x][y] == '#') return;
	
	if (x == 0 || x == n - 1 || y == 0 || y == m - 1) escape = true;
	if (adjmtx[x][y] == 'k') sheepCnt += 1;
	else if (adjmtx[x][y] == 'v') wolvCnt += 1;

	vis[x][y] = true;
	for (int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i]);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	vis.assign(n, vector<bool>(m, false));
	adjmtx.assign(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> adjmtx[i][j];
		}
	}

	int sheepAns = 0, wolvAns = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char animal = adjmtx[i][j];
			if ((animal == 'k' || animal == 'v') && !vis[i][j]) {
				escape = false;
				sheepCnt = 0, wolvCnt = 0;
				dfs(i, j);
				if (escape)	sheepAns += sheepCnt, wolvAns += wolvCnt;
				else if (sheepCnt > wolvCnt) sheepAns += sheepCnt;
				else wolvAns += wolvCnt;
			}
		}
	}

	return cout << sheepAns << " " << wolvAns, 0;
}
