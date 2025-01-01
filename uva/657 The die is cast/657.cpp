#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m, cnt;
vector<vector<char>> grid;
bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs2(int x, int y) {
    if (!valid(x, y) || grid[x][y] != 'X') return;
    grid[x][y] = '#';
    for (int i = 0; i < 4; i++) dfs2(x + dx[i], y + dy[i]);
}

void dfs(int x, int y) {
    if (!valid(x, y) || grid[x][y] == '.' || grid[x][y] == '#') return;
    if (grid[x][y] == 'X') {
		dfs2(x, y), cnt++;
	} else grid[x][y] = '#';
    for (int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i]);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    int testcase = 1;
    while (cin >> m >> n && n && m) {
        grid.assign(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
			}
		}

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') {
                    cnt = 0;
                    dfs(i, j);
                    if (cnt) ans.push_back(cnt);
                }
			}
		}

        sort(ans.begin(), ans.end());
        cout << "Throw " << testcase++ << el;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i < ans.size() - 1) cout << " ";
        }

        cout << el << el;
    }

    return 0;
}
