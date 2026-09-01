#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, L, R;    std::cin >> n >> L >> R;
    std::string s;  std::cin >> s;
    
    std::vector<int> ch[26]; 
    for (int i = 0; i < n; i++) ch[s[i] - 'a'].push_back(i);

    i64 ans = 0;
    for (int i = 0; i < 26; i++) { // maybe bs?
        int m = (int)ch[i].size();
        for (int l = 0; l < m; l++) {
            auto curL = std::lower_bound(ch[i].begin(), ch[i].end(), ch[i][l] + L);
            auto curR = std::upper_bound(ch[i].begin(), ch[i].end(), ch[i][l] + R);
            ans += curR - curL;
        }
    }

    return std::cout << ans, 0;
}
