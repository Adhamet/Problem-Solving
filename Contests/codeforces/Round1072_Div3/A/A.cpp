#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        if (n == 2) std::cout << 2 << '\n';
        else if (n == 3) std::cout << 3 << '\n';
        else if (n&1) std::cout << 1 << '\n';
        else std::cout << 0 << '\n';
    }

    return 0;
}
