#include <bits/stdc++.h>

using i64 = long long;

// 1: 0 1 2 3 4
// 2: 1 0 1 2 3   ------->   1 0 1 2 3
// 3: 2 1 0 1 2   ------>    3 2 1 2 3 -= 2 2 0 0 0, sub first eles twice --> 0 2 0 0 0, div by 2 --> 0 1 0 0 0
// 4: 3 2 1 0 1
// 5: 4 3 2 1 0

// 5 + 1 = 4x each element
// ^-<-= tot = 1+5/4 : (f[0] + f[n-1] / (n - 1))

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<i64> f(n);
        for (int i = 0; i < n; i++) std::cin >> f[i];

        i64 tot = (f[0] + f[n-1]) / (n-1);

        i64 rollingSm = (f[1] + tot - f[0]) / 2;
        std::cout << rollingSm << ' ';
        for (int i = 2; i < n; i++) {
            i64 cur = (f[i] + tot - f[i - 1] - (2 * rollingSm)) / 2;
            std::cout << cur << ' ';
            rollingSm += cur;
        }

        std::cout << tot - rollingSm << '\n';
    }

    return 0;
}
