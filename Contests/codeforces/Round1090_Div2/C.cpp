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
        int n;  std::cin >> n;
        std::deque<int> p(3*n);
        std::iota(p.begin(), p.end(), 1);
        debug(p);

        for (int i = 0; i < n; i++) {
            std::cout << p.front() << ' ';
            p.pop_front();
            std::cout << p.back() << ' ';
            p.pop_back();
            std::cout << p.back() << ' ';
            p.pop_back();
        }

        std::cout << '\n';
    }

    return 0;
}
