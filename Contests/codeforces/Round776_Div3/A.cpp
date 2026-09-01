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
        std::string s;  std::cin >> s;
        char ch;    std::cin >> ch;
        int n = s.size();

        bool acc = false;
        for (int i = 1; i <= n; i++) if (s[i-1] == ch) {
            if ((i-1) % 2 == 0 && (n-i) % 2 == 0) {
                acc = true;
            }
        }

        std::cout << (acc? "YES": "NO") << '\n';
    }

    return 0;
}
