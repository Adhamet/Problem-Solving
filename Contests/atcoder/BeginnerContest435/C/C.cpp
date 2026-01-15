#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    std::vector<int> vis(n+1, false);

    int me = 1, curMx = 1, nxtMx = 1;
    while (!vis[curMx]) {
        // 1 2 3 4 5 6 7 8 9
        // 5 4 3 1 1 2 3 4 5
        for (int i = me; i <= std::min(n, curMx); i++) {
            nxtMx = std::max(nxtMx, i + a[i] - 1);
            nxtMx = std::min(n, nxtMx);
            vis[i] = true;
        }
        me = curMx + 1;
        curMx = nxtMx;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) if (vis[i])
        ans += 1;

    return std::cout << ans, 0;
}
