#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        i64 n, w;   std::cin >> n >> w;
        i64 k = 0;
        if (n > w - 1) k = (n - (w - 1) + w - 1) / w;
        std::cout << n - k << '\n';
    }

    return 0;
}
