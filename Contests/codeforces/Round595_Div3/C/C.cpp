#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXN = 39;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int q;  std::cin >> q;

    i64 pow3[39];   pow3[0] = 1;
    for (int i = 1; i < 39; i++) pow3[i] = pow3[i-1] * 3;

    while (q--) {
        int n;  std::cin >> n;

        

        std::cout << ans << '\n';
    }

    return 0;
}
