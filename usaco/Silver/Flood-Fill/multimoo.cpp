#include <bits/stdc++.h>
using namespace std;

const int MAXN = 250;
int n, grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

int floodfill(int sz, int r, int c, int col1, int col2) {
	if((r < 0 || r >= n || c < 0 || c >= n) || (grid[r][c] != col1 && grid[r][c] != col2) || vis[r][c]) {
		return sz;
	}

    ++sz;
	vis[r][c] = 1;
	sz = floodfill(sz, r, c + 1, col1, col2);
	sz = floodfill(sz, r, c - 1, col1, col2);
	sz = floodfill(sz, r - 1, c, col1, col2);
	sz = floodfill(sz, r + 1, c, col1, col2);
	return sz;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("multimoo.in", "r", stdin);
	freopen("multimoo.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

    // individual
    int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(!vis[i][j]) {
				ans = max(ans, floodfill(0, i, j, grid[i][j], grid[i][j]));
			}
		}
	}

	cout << ans << '\n';
    // teams: Xs then Ys
    for (int i = 1; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (ans >= n * n / 2) {
				cout << ans << '\n';
				return 0;
			}

			if(grid[i][j] != grid[i-1][j]) {
				memset(vis, 0, sizeof(vis));
				ans = max(ans, floodfill(0, i, j, grid[i][j], grid[i - 1][j]));
			}
		}
	}

    for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (ans >= n*n/2) {
				cout << ans << '\n';
				return 0;
			}

			if (grid[i][j] != grid[i][j-1]) {
				memset(vis, 0, sizeof(vis));
				ans = max(ans, floodfill(0, i, j, grid[i][j], grid[i][j - 1]));
			}
		}
	}

    cout << ans << '\n';
    return 0;
}
