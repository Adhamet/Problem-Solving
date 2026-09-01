#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    i64 n;
    i64 x, y, z;
    std::cin >> n >> x >> y >> z;
    i64 sauces = std::min(n, z/2);

    bool ok = false;
    if (x - (n*2) - sauces < 0) ok = true;
    if (y - (n*2) - sauces < 0) ok = true;

    return std::cout << (ok? "yes": "no"), 0;
}
