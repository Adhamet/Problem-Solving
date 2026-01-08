#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, mod;
    std::cin >> n >> mod;

    i64 sol = 1;
    for (int i = 0; i < n; i++) {
        sol = (sol * (i + 1) + (i&1? 1: -1)) % mod;
        if (sol < 0) sol += mod;
        std::cout << sol << ' ';
    } 

    return 0;
}

