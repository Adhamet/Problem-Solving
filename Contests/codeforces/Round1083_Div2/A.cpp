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
        std::vector<int> a(n);
        int ugly1 = -1, ugly2 = -1;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            mx = std::max(a[i], mx);
            if (mx == i + 1) {
                if (ugly1 == -1) ugly1 = i;
                else if (ugly2 == -1) ugly2 = i;
            }
        }

        if (ugly2 != -1) {
            int posN = -1;
            for (int i = 0; i < n; ++i) if (a[i] == n) { 
                posN = i; 
                break;
            }
            if (posN != -1 && posN != 0) std::swap(a[posN], a[0]);
        }

        for (auto x: a) std::cout << x << ' ';
        std::cout << '\n';
    }

    return 0;
}
