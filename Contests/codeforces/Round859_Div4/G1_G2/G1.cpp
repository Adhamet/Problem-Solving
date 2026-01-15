#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        int c[n];
        for (int i = 0; i < n; i++) std::cin >> c[i];
        std::sort(c, c+n);

        if (c[0] != 1) {
            std::cout << "NO\n";
            continue;
        }

        i64 sm = 1;
        bool acc = true;
        for (int i = 1; i < n; i++) {
            if (c[i] > sm) {
                acc = false;
                break;
            }
            sm += c[i];
        }

        std::cout << (acc? "YES\n": "NO\n");
    }

    return 0;
}
