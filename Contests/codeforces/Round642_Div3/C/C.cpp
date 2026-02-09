#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        i64 n;  std::cin >> n;
        i64 md = (n - 1) / 2;
        std::cout << (i64)8 * (md * (md + 1) * (2 * md + 1) / 6) << '\n';
    }

    return 0;
}
