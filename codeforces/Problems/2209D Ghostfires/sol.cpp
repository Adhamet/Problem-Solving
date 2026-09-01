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
    std::vector<std::pair<int, char>> cnt(3);
    std::cin >> cnt[0].first >> cnt[1].first >> cnt[2].first;
    cnt[0].second = 'R', cnt[1].second = 'G', cnt[2].second = 'B';
    
    std::string s = "";
    while (true) {
        int len = s.length();

        std::sort(cnt.begin(), cnt.end(), [&](const auto& a, const auto& b) {
            if (a.first != b.first) return a.first > b.first;
            bool aMatch = (len >= 2 && s[len - 2] == a.second);
            bool bMatch = (len >= 2 && s[len - 2] == b.second);
            return aMatch > bMatch;
        });
        
        bool placed = false;
        for (int i = 0; i < 3; ++i) {
            if (cnt[i].first == 0) continue; 
            
            char c = cnt[i].second;
            if (len >= 1 && s[len - 1] == c) continue;
            if (len >= 3 && s[len - 3] == c) continue;
            
            s += c, cnt[i].first--;
            placed = true;
            break; 
        }
        
        if (!placed) break;
    }
    
    std::cout << s << '\n';
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    int t;  std::cin >> t;
    while (t--) solve();
    return 0;
}
