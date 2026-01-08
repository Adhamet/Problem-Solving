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
        int n, d, i;
        std::cin >> n >> d >> i;

        int bases = 0, ta7wee4 = 0;

        auto calc = [&](int x) {
            if ((x * 2) - 1 <= d) {
                d -= ((n - i) * 2) - 1;
                bases += x;
                ta7wee4 = x;
            } else {
                if (d & 1) bases += (d / 2) + 1;
                else bases += (d / 2);
                d = 0;
            }
        };


        if (i != n && i != 1 && n - i >= i - 1) {
            calc(n - i);
            debug(bases);
            if (d) calc(i - 1);
        } else if (i != 1) {
            calc(i - 1);
            if (d) calc(n - i);
        }

        std::cout << bases << '\n';
    }

    return 0;
}
