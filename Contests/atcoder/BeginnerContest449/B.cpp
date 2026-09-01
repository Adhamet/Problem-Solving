#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int r, c;   std::cin >> r >> c;
    int q;  std::cin >> q;

    while (q--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int curR;   std::cin >> curR;
            std::cout << curR * c << '\n';
            r -= curR;
        } else {
            int curC;   std::cin >> curC;
            std::cout << curC * r << '\n';
            c -= curC;
        }
    }

    return 0;
}
