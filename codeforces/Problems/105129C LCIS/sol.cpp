#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

i64 binexp(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        i64 x, d;   std::cin >> x >> d;
        std::string s = std::to_string(x);
        int n = (int)s.size();

        i64 ans = 0;
        int i = n - 1;
        bool carry = 0;
        while (i >= 0) {
            if (carry) s[i]++, carry = 0;
            if (s[i] > '9') s[i] = '0', carry = 1;

            if (s[i] - '0' == d) {
                char toBe = 0;
                if (d == 0) toBe = '1';
                else toBe = '0';
                
                i64 cur = 0, target = 0;
                for (int j = i + 1; j < n; j++) {
                    cur = cur * 10 + (s[j] - '0');
                    target = target * 10 + (toBe - '0');
                    s[j] = toBe;
                }
                
                ans += binexp(10, n-i-1) + target - cur;
                
                s[i]++;
                if (s[i] > '9') s[i] = '0', carry = 1;
            }
            
            i--;
        }

        std::cout << ans << '\n';
    }

    return 0;
}
