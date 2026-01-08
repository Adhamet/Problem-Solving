#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

void solve() {
    int k, x;   std::cin >> k >> x;
    int i = 0;
    while (k) {
        i += x;
        k--;
    }
    std::cout << i + 1 << '\n';
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
