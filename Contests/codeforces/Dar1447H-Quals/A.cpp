#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, x, y;    std::cin >> n >> x >> y;

        if (x > n || y > n) {
            std::cout << "Impossible" << '\n';
            continue;
        }
        if (x == y) {
            std::cout << "Possible" << '\n';
            continue;
        }

        int lead = std::abs(x - y);
        int mx = std::max(x, y);
        int q = n - lead + 1;

        bool possible = false;
        for (int p = q - 1; p <= q + 1; p++) {
            if (p >= 0 && p <= n && p >= mx) {
                possible = true;
                break;
            }
        }

        std::cout << (possible? "Possible": "Impossible") << '\n';
    }

    return 0;
}
