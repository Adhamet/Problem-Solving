#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int p, q;   std::cin >> p >> q;
    int p2, q2; p2 = p + 99, q2 = q + 99;

    int x, y;   std::cin >> x >> y;
    if (x >= p && y >= q && x <= p2 && y <= q2) {
        std::cout << "Yes\n";
    } else std::cout << "No\n";

    return 0;
}
