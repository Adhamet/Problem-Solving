#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int q;  std::cin >> q;
    while (q--) {
        i64 n, a, b;    std::cin >> n >> a >> b;
        std::cout << std::min(n*a, b*(n/2)+a*(n%2)) << '\n';
    }

    return 0;
}
