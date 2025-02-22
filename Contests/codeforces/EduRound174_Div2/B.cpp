#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int dx[] = {0, 0, -1, 1};
const  int dy[] = {-1, 1, 0, 0};
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        unordered_set<int> cols;
        unordered_map<int, bool> adjacent;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                cols.insert(grid[i][j]);
                adjacent[grid[i][j]] = false;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int col = grid[i][j];
                if (adjacent[col]) continue;

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (grid[ni][nj] == col) {
                            adjacent[col] = true;
                            break;
                        }
                    }
                }
            }
        }

        unordered_map<int, int> steps;
        for (auto &col: cols) steps[col] = (adjacent[col]? 2: 1);

        int tot = 0;
        for (auto &col: cols) tot += steps[col];

        int minTot = LLONG_MAX;
        for (auto &col: cols) {
            int curr = tot - steps[col];
            minTot = min(minTot, curr); 
        }

        cout << minTot << el;
    }

    return 0;
}