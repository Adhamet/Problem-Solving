#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

void solve() {
    int n;  std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
   
    i64 tot = 0;
    for (int i = 0; i < n - 1; i++) 
        tot += std::abs(a[i] - a[i+1]);

    i64 ans = tot - std::abs(a[0] - a[1]);
    for (int i = 1; i < n - 1; i++) {
        i64 contrib1 = std::abs(a[i-1] - a[i]);
        i64 contrib2 = std::abs(a[i] - a[i+1]);
        i64 contrib3 = std::abs(a[i-1] - a[i+1]);
        ans = std::min(ans, tot-contrib1-contrib2+contrib3);
    }
    ans = std::min(ans, tot - std::abs(a[n-1] - a[n-2]));

    std::cout << ans << '\n';
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
