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

    int t;  std::cin >> t;
    while (t--) {
        int n, x;   std::cin >> n >> x;
        int floor = 1;
        if (n <= 2) std::cout << floor << '\n';
        else {
            n -= 2;
            while (n > 0) {
                n -= x;
                floor += 1;
            }
            std::cout << floor << '\n';
        }
    }

    return 0;
}
