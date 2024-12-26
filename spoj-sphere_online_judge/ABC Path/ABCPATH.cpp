#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

const int MAXN = 55;
const int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
const int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int h, w, mxPath = 0;
vector<vector<int>> vis(MAXN, vector<int>(MAXN, 0));
char adjMtrx[MAXN][MAXN];

void init() {
	mxPath = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			vis[i][j] = false;
		}
	}
}

void dfs_floodfill(int x, int y, char curr, int pathLen) {
	if (x < 0 || x >= h || y < 0 || y >= w || adjMtrx[x][y] != curr || vis[x][y]) return;
	vis[x][y] = true;
	mxPath = max(mxPath, pathLen);
	for (int i = 0; i < 8; i++) dfs_floodfill(x + dx[i], y + dy[i], curr + 1, pathLen + 1);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int testcase = 1;
	while (cin >> h >> w && h && w) {
		init();
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> adjMtrx[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (adjMtrx[i][j] == 'A') dfs_floodfill(i, j, 'A', 1);
			}
		}
		
		cout << "Case " << testcase++ << ": " << mxPath << el;
	}

	return 0;
}
