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
        
        i64 accu = 0;
        for (int i = 0; i < n; i++) {
            i64 a, b;
            char ch_b;
            std::cin >> a >> ch_b;

            if (ch_b == 'A') b = 10;
            else b = ch_b - '0';

            accu += (a * b);
        }

        std::cout << (accu % 5 == 0? "Yes": "No") << '\n';
    }

    return 0;
}
