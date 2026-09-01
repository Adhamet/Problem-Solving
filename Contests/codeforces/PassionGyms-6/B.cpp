#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;  std::cin >> n;
    std::vector<int> freq(n + 2, 0);
    for (int i = 0; i < n; i++) {
        int x;  std::cin >> x;  
        freq[x]++;
    }
    
    bool checker = false;
    for (int i = 1; i <= n; i++) if (freq[i] > 1) checker = true;

    if (!checker && n % 2 == 0) std::cout << "Bob\n";
    else std::cout << "Alice\n";
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t;  std::cin >> t;
    while (t--) solve();    
    return 0;
}
