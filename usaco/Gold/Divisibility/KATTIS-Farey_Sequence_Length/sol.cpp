#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

void solve() {
    int testCase, n;
    std::cin >> testCase >> n;

    int phi[n + 3];
    for (int i = 0; i <= n; i++) phi[i] = i;
    phi[0] = 0, phi[1] = 1;
    
    for (int i = 2; i <= n; i++) if (phi[i] == i) {
        for (int j = i; j <= n; j += i)
            phi[j] -= phi[j] / i;
    }

    i64 ans = 1;
    for (int i = 1; i <= n; i++) ans += phi[i];

    std::cout << testCase << ' ' << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
