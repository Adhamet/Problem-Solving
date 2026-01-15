#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    i64 a, b;   std::cin >> a >> b;
    while (b--) {
        a *= 2;
    }

    return std::cout << a, 0;
}
