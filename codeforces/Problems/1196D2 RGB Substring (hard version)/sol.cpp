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

    std::string strs[3] = {"RGB", "BRG", "GBR"};
    // its always RGBRGBRGB as a continoum
    // we either start with nothing, then go RGB...
    // or we start with B, then continue with RGB... (B-RG-B)
    // or we start with GB, then continue with RGB.. (GB-R-GB)
    //
    // in one loop we could try to view with like a prefix
    // how RGB, BRG, GBR go
    // 0 1 2 3 4 5 6 7 8 9 10
    // R G G B R B R G B 
    // for RGB its supposed to be
    // R G B R G B R G B    
    // prefix will be
    // 1 2 2 2 2 3 4 5 6
    //
    // we loop on each prefix find the max
    // pref[i + k] - pref[i];   for each type of string.
    // the answer will be k - max
    int q;  std::cin >> q;
    while (q--) {
        int n, k;
        std::string s;
        std::cin >> n >> k >> s;
        
        std::vector<int> pref[3];
        for (int i = 0; i < 3; i++)
            pref[i].resize(n, 0);

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                pref[0][i] += pref[0][i-1];
                pref[1][i] += pref[1][i-1];
                pref[2][i] += pref[2][i-1];
            }
            pref[0][i] += (strs[0][i%3] == s[i]);
            pref[1][i] += (strs[1][i%3] == s[i]);
            pref[2][i] += (strs[2][i%3] == s[i]);
        }

        // 4
        // 0 1 2 3

        // R B R G R
        // 1 1 1 1 1 (RGB)
        // 0 0 0 0 1 (BRG)
        // 0 1 2 3 3 (BRG)
        // for (int i = 0; i < n; i++) debug(pref[0][i]);
        // for (int i = 0; i < n; i++) debug(pref[1][i]);
        // for (int i = 0; i < n; i++) debug(pref[2][i]);

        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (i + k - 1 >= n) break;
            mx = std::max(mx, pref[0][i+k-1] - (i==0? 0: pref[0][i-1]));
            mx = std::max(mx, pref[1][i+k-1] - (i==0? 0: pref[1][i-1]));
            mx = std::max(mx, pref[2][i+k-1] - (i==0? 0: pref[2][i-1]));
        }

        std::cout << k - mx << '\n';
    }

    return 0;
}

