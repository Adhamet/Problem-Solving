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
        std::vector<int> freq(10+1, 0);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int x;  std::cin >> x;
            mx = std::max(mx, x);
            freq[x]++;
        }

        std::cout << freq[mx] << '\n';
    }

    return 0;
}
