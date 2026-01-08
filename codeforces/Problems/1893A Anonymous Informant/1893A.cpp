#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;   std::cin >> n >> k;
    int b[n];
    for (int i = 0; i < n; i++) std::cin >> b[i];

    std::vector<bool> vis(n);
    int idx = n - 1;
    while (k--) {
        if (vis[idx]) return void(std::cout << "Yes\n");
        if (b[idx] > n) return void(std::cout << "No\n");
        vis[idx] = true;
        idx -= b[idx];
        if (idx < 0) idx += n;
    }

    std::cout << "Yes\n";
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
