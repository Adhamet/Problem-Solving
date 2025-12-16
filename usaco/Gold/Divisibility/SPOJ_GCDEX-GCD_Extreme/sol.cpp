#include <bits/stdc++.h>
using i64 = long long;

constexpr int MXN = 1e6+5;

i64 phi[MXN];
i64 gSum[MXN];

void precompute_phi() {
    for (int i = 0; i < MXN; i++) phi[i] = i;
    phi[0] = 0; phi[1] = 1;

    for (int i = 2; i < MXN; i++) if (phi[i] == i) {
        for (int j = i; j < MXN; j += i)
            phi[j] -= phi[j] / i;
    }
}

void precompute_G() {
    i64 F[MXN] = {0};

    for (int i = 1; i < MXN; i++)
        for (int j = i; j < MXN; j += i)
            F[j] += i * phi[j/i];

    gSum[0] = 0; gSum[1] = 0;
    for (int n = 2; n < MXN; n++)
        gSum[n] = gSum[n-1] + F[n] - n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    precompute_phi();
    precompute_G();

    int n;
    while (std::cin >> n && n) 
        std::cout << gSum[n] << "\n";

    return 0;
}

