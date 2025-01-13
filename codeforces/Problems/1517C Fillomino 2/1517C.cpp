#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int dr[] = {0, 1};
const int dc[] = {-1, 0};
const int MAXN = 505;
int n;
vector<int> cnt(MAXN);
vector<vector<bool>> vis(MAXN, vector<bool>(MAXN));
vector<vector<int>> grid(MAXN, vector<int>(MAXN, -1));
bool valid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c <= r;
}

void dfs(int r, int c, int val) {
    if (!valid(r, c) || vis[r][c] || cnt[val] == val) return;
    vis[r][c] = true;
    cnt[val] += 1;
    grid[r][c] = val;
    for (int i = 0; i < 2; ++i) dfs(r + dr[i], c + dc[i], val);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> grid[i][i];
    for (int i = 0; i < n; ++i) dfs(i, i, grid[i][i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << grid[i][j] << ' ';
        }
        cout << el;
    }
    return 0;
}
