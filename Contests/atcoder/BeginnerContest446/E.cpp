#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

inline i64 addm(i64 a, i64 b, i64 m) { a += b; if (a >= m) a -= m; return a; }

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    i64 M, A, B;
    std::cin >> M >> A >> B;

    // [0: !vis][1: vis][2: vis & !acc][3: vis & acc}]
    std::vector<std::vector<int>> vis(M, std::vector<int>(M, 0));

    auto work = [&](auto &&self, i64 x, i64 y) -> int {
        if (vis[x][y] != 0 && vis[x][y] != 1) {
            if (vis[x][y] == 1) return vis[x][y] = 3;
            return vis[x][y];
        }

        i64 z = addm(A*y%M, B*x%M,  M);
        if (z == 0) return vis[x][y] = 2;
        
        vis[x][y] = 1;
        int state = self(self, y, z);
        return vis[x][y] = state;
    };

    int ans = 0;
    for (i64 i = 1; i < M; i++) {
        for (i64 j = 1; j < M; j++) {
            if (vis[i][j] == 0 && work(work, i, j) == 3) ans++;
            else if (vis[i][j] == 3) ans++;
        }
    }

    return std::cout << ans, 0;
}
