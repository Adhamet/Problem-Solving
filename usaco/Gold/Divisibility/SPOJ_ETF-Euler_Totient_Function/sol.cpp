#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXN = 1e6+5;
i64 phi[MXN];

void precompute_phi() {
    for (int i = 0; i < MXN; i++) phi[i] = i;
    phi[0] = 0; 
    phi[1] = 1;

    for (int i = 2; i < MXN; i++) {
        if (phi[i] == i) {
            for (int j = i; j < MXN; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    precompute_phi();

    int T;
    std::cin >> T;
    while (T--) {
        int n;
        std::cin >> n;
        std::cout << phi[n] << "\n";
    }

    return 0;
}

