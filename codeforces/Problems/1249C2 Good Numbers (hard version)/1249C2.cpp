#include <bits/stdc++.h>

using i64 = long long;


#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

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

    int q;  std::cin >> q;
    while (q--) {
        i64 n;  std::cin >> n;

        std::vector<i64> mask;
        while (n) {
            mask.push_back(n%3);
            n /= 3;
        }

        int m = (int)mask.size();
        int i = 0, carry = 0;
        while (i < m) {
            if (mask[i] == 2) {
                carry = 1;
                for (int j = i; j >= 0; j--) mask[j] = 0;
            }
            else if (mask[i] == 1 && carry) {
                for (int j = i; j >= 0; j--) mask[j] = 0;
            } else if (mask[i] == 0 && carry) mask[i] = 1, carry = 0;
            i++;
        }
        if (carry) {
            for (int j = m-1; j >= 0; j--) mask[j] = 0;
            mask.push_back(1);
        }

        i64 ans = 0;
        for (int i = 0; i < (int)mask.size(); i++) {
            if (mask[i]) ans += binexp(3,i);
        }

        std::cout << ans << '\n';
    }

    return 0;
}
