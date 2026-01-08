#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

void solve() {
    std::string t;  std::cin >> t;
    int n = (int)t.size();

    std::string s = t;
    s[0] = 's', s[n-1] = 's';
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == 'u') {
            if (s[i-1] != 's') {
                s[i-1] = 's';
            }
            if (s[i+1] != 's') {
                s[i+1] = 's';
            }
        }
    }

    int diff = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            diff += 1;
        }
    }

    std::cout << diff << '\n';
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
