#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

void solve() {
    int n;  std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());

    std::cout << std::max(a[0], (n>1? a[1]-a[0]: -1)) << '\n';
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
