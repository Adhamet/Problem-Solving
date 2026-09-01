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
int mem[MXN][MXN][3];
int n, k;
std::string s;

int go(int idx, int curK, int ch, const std::string& t) {
    if (idx <= n && curK >= k) return 0;
    if (idx == n) {
        if (curK >= k) return 0;
        else return (int)1e9;
    }

    int &ret = mem[idx][curK][ch];
    if (~ret) return ret;
    ret = (int)1e9;

    if (s[idx] == t[ch]) ret = go(idx+1, curK+1, (ch+1)%3, t);
    if (s[idx] != t[ch]) {    
        ret = go(idx+1, curK, ch, t);
        ret = std::min(ret, 1 + go(idx+1, curK+1, (ch+1)%3, t));
    }

    return ret;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int q;  std::cin >> q;
    while (q--) {
        std::cin >> n >> k >> s;
        for (int a = 0; a < n; a++)
            for (int b = 0; b <= k; b++)
                for (int c = 0; c < 3; c++)
                    mem[a][b][c] = -1;
        int ans1 = go(0,0,0, "RGB");
        for (int a = 0; a < n; a++)
            for (int b = 0; b <= k; b++)
                for (int c = 0; c < 3; c++)
                    mem[a][b][c] = -1;
        int ans2 = go(0,0,0, "GBR");
        for (int a = 0; a < n; a++)
            for (int b = 0; b <= k; b++)
                for (int c = 0; c < 3; c++)
                    mem[a][b][c] = -1;
        int ans3 = go(0,0,0, "BRG");
        for (int a = 0; a < n; a++)
            for (int b = 0; b <= k; b++)
                for (int c = 0; c < 3; c++)
                    mem[a][b][c] = -1;

        std::cout << std::min({ans1,ans2,ans3}) << '\n';
    }

    return 0;
}
