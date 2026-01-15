#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        int evs = 0, ods = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            if (x & 1) ods += x;
            else evs += x;
        }

        if (evs > ods) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}
