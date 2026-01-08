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
    std::string s;
    std::cin >> s;

    std::vector<int> vec;
    vec.reserve(500);
    for (int i = 0; i < (int)s.size(); i++) {
        vec.push_back(s[i]);
        if ((int)vec.size() >= 2) {
            int j = (int)vec.size() - 1;

            char cur = vec[j], lst = vec[j-1];
            if (cur != 'Y' || lst != 'Y') {
                vec.pop_back();
                vec.pop_back();
                if (cur == 'Y' || lst == 'Y')
                    vec.push_back('Y');
                else vec.push_back('N');
            }
        }
    }

    std::cout << ((int)vec.size() > 1? "NO\n": "YES\n");
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
