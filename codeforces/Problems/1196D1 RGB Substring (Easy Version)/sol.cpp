#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

constexpr int MXN = 2003;
int mem[MXN][3];
int n, k;
std::string s;

int go(int idx, int ch, const int end, const std::string& t) {
    if (idx >= end) return 0;

    int &ret = mem[idx][ch];
    if (~ret) return ret;
    ret = INT_MAX;

    if (t[ch] == s[idx]) {
        ret = std::min(ret, go(idx+1, (ch+1)%3, end, t));
    } else ret = std::min(ret, 1 + go(idx+1, (ch+1)%3, end, t));

    return ret;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    std::string strs[3] = {"RGB", "GBR", "BRG"};

    int q;  std::cin >> q;
    while (q--) {
        std::cin >> n >> k >> s;
        
        int ans = INT_MAX;
        for (auto &str: strs) {
            // debug(str);
            for (int i = 0; i < n; i++) {
                if (i + k > n) break;
                // start at each idx

                // -- reset mem
                for (int a = 0; a < n; a++)
                    for (int b = 0; b < 3; b++)
                        mem[a][b] = -1;
               
                // go
                ans = std::min(ans, go(i, 0, i+k, str));
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
