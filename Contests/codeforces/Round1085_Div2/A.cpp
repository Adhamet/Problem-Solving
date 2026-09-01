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
        std::string s;
        std::cin >> s;

        // step one put as many 1s as possible
        std::string oneS = s;
        for (int i = 0; i < n - 1; i++) {
            if (i > 0 && oneS[i-1] == oneS[i+1] && oneS[i-1] == '1') {
                oneS[i] = '1';
            }
        }

        int cntO = 0;
        for (int i = 0; i < n; i++) cntO += (oneS[i] == '1');

        for (int i = 0; i < n - 1; i++) {
            if (i > 0 && oneS[i-1] == oneS[i+1] && oneS[i-1] == '1') {
                // debug(i);
                oneS[i] = '0';
            }
        }

        int cntZ = 0;
        for (int i = 0; i < n; i++) cntZ += (oneS[i] == '1');

        std::cout << cntZ << ' ' << cntO << '\n';
    }

    return 0;
}
