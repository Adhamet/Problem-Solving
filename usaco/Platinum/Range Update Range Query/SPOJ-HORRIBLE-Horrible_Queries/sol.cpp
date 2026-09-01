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

    auto pointSum = [](const std::vector<i64>& bit, int i, int n) -> i64 {
        i64 sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    };

    int t;  std::cin >> t;
    while (t--) {
        int n, c;   std::cin >> n >> c;
        std::vector<i64> bit1(n+1), bit2(n+1);

        while (c--) {
            int type;
            std::cin >> type;
            if (type == 0) {
                int p, q;
                i64 v;
                std::cin >> p >> q >> v;
                for (int i = p; i <= n; i += i & -i) {
                    bit1[i] += v;
                    bit2[i] += v * (p - 1);
                }
                for (int i = q+1; i <= n; i += i & -i) {
                    bit1[i] -= v;
                    bit2[i] -= v * q;
                }
            } else { // type == 1    sz * (bit1[k]) - bit2[k];
                int p, q;
                std::cin >> p >> q;
                p--;
                i64 sum1 = p * pointSum(bit1, p, n) - pointSum(bit2, p, n);
                i64 sum2 = q * pointSum(bit1, q, n) - pointSum(bit2, q, n);
                std::cout << sum2 - sum1 << '\n';
            }
        }
    }

    return 0;
}
