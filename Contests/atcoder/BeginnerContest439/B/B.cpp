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

    int k = 10000;
    while (k) {
        std::string str = std::to_string(n);

        int cur = 0;
        for (auto ch: str) {
            cur += std::pow(ch-'0', 2);
        }

        n = cur;
        k--;
    }
    
    if (n == 1) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}
