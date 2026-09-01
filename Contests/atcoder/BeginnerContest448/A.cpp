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

    int n, x;   std::cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int input;  std::cin >> input;
        debug(input);
        if (input < x) {
            x = input;
            std::cout << 1 << '\n';
        } else std::cout << 0 << '\n';
    }

    return 0;
}
