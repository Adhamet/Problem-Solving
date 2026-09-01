#include <bits/stdc++.h>

// -- Don't use with doubles -----------
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
// -------------------------------------
#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};
const int MXN = (int)1e3+5;

int n, m;
char grid[MXN][MXN];
bool vis[MXN][MXN];

inline bool inborder(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

inline bool onborder(int r, int c) {
    return r == 0 || r == n-1 || c == 0 || c == m-1;
}

void dfs(int r, int c, bool& isborder) {
    vis[r][c] = true;
    if (onborder(r, c)) isborder = true;
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (inborder(nr, nc) && !vis[nr][nc] && grid[nr][nc] == '.') {
            dfs(nr, nc, isborder);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> grid[i][j];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                bool isborder = false;
                dfs(i, j, isborder);
                if (!isborder) ans++;
            }
        }
    }

    return std::cout << ans, 0;
}
