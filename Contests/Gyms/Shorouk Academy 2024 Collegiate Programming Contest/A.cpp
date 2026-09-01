#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

i64 binpow(i64 a, i64 b) {
    i64 res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    // two operations
    // (1): before limitations ex: 463, (4), has 3 digits before
    // it that takes 10 * 10, so 1,2,3 each one of them take
    // 10*10 for the rest of the digits
    // (2): in the limitation ex: 463, (4), it is one digit
    // and then we recalculate step (1) for 63.

    int t;  std::cin >> t;
    while (t--) {
        i64 n;  std::cin >> n;
        std::string s = std::to_string(n);

        i64 ans = 0;
        int digits = (int)s.size();

        for (int i = 1; i < digits; i += 2)
            ans += (9 * binpow(10, i - 1));

        if (digits % 2 != 0) {
            for (int i = 0; i < digits; i++) {
                int curCh = s[i] - '0';
                if (curCh > (i == 0)) {
                    ans += (curCh - (i==0)) * binpow(10, digits-i-1);
                }
            }

            ans += 1;
        }

        std::cout << ans << '\n';
    }

    return 0;
}
