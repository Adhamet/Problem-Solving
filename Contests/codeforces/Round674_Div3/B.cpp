#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

struct tile {
    int x1, y1;
    int x2, y2;
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, m;   std::cin >> n >> m;

        tile tiles[n];
        // debug(m);
        bool op1 = false, op2 = false;
        for (int i = 0; i < n; i++) {
            std::cin >> tiles[i].x1 >> tiles[i].y1;
            std::cin >> tiles[i].x2 >> tiles[i].y2;

            // debug(tiles[i].x1, tiles[i].y1);
            // debug(tiles[i].x2, tiles[i].y2);
            if (!op1) {
                op1 = (tiles[i].x2 == tiles[i].y1);
            }
            if (!op2) {
                op2 = ((tiles[i].x2 == tiles[i].y1) && (tiles[i].x1 == tiles[i].y2));
            }
        }
        // std::cerr << '\n';

        if (m & 1) std::cout << "NO\n";
        else std::cout << (op1? "YES\n": "NO\n");
    }

    return 0;
}
