#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        i64 n, m;   std::cin >> n >> m;

        if (n == 1) std::cout << 0 << '\n';
        else if (n == 2) std::cout << m << '\n';
        else std::cout << m*2 << '\n';
    }

    return 0;
}
