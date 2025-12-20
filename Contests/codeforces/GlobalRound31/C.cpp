#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
#define MSB(x) (1LL << (63 - __builtin_clzll(x)))
#define MSB_IDX(x) (63 - __builtin_clzll(x))
#define LSB(x) ((x) & -(x))
#define LSB_IDX(x) (__builtin_ctzll(x))
#define DROP_LSB(x) ((x) & ((x) - 1))
#define IS_POW2(x) ((x) && !((x) & ((x) - 1)))
#define CLZ(x) (__builtin_clzll(x))   // undefined if x == 0
#define CTZ(x) (__builtin_ctzll(x))   // undefined if x == 0

void solve() {
    i64 n, k;   std::cin >> n >> k;
    if (k == 1) std::cout << n << '\n';
    else {
        if (k & 1) {
            for (int i = 0; i < k; i++) {
                if (i > 0) std::cout << ' ';
                std::cout << n;
            }
            std::cout << '\n';
        } else {
            for (int i = 0; i < k - 2; i++) {
                if (i > 0) std::cout << ' ';
                std::cout << n; 
            }

            int msb = MSB_IDX(n);
            i64 x1 = 0, x2 = 0;
            x1 |= (1LL << msb);

            for (int bit = msb - 1; bit >= 0; bit--) {
                if (n & (1LL << bit)) {
                    if (x1 <= x2) x1 |= (1LL << bit);
                    else x2 |= (1LL << bit);
                } else {
                    i64 op1 = x1 | (1LL << bit);
                    i64 op2 = x2 | (1LL << bit);
                    if (op1 <= n && op2 <= n) {
                        x1 = op1;
                        x2 = op2;
                    }
                }
            }

            if (k != 2) std::cout << ' ' << x1 << ' ' << x2 << '\n';
            else std::cout << x1 << ' ' << x2 << '\n';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
