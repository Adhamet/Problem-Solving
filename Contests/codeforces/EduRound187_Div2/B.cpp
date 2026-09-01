#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

i64 mem[20][200];
std::string s;
int n;

i64 F(std::string s) {
    i64 val = 0;
    for (i64 i = 0; i < (i64)s.size(); i++) {
        val += (s[i] - '0');
    }
    return val;
}

i64 go(i64 idx, i64 sum) {
    if (sum > 9*n) return (i64)1e9;
    if (idx == n) {
        if (sum == F(std::to_string(sum))) return 0;
        else return (i64)1e9;
    }

    i64 &ret = mem[idx][sum];
    if (~ret) return ret;
    ret = (i64)1e9;

    i64 val = s[idx] - '0';

    ret = go(idx + 1, sum + val);
    for (i64 i = 0; i <= 9; i++) {
        if (i == val) continue;
        if (idx == 0 && n > 1 && i == 0) continue;
        ret = std::min(ret, 1 + go(idx + 1, sum + i));    
    }

    return ret;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    i64 t;  std::cin >> t;
    while (t--) {
        for (i64 i = 0; i < 20; i++) {
            for (i64 j = 0; j < 200; j++) {
                mem[i][j] = -1;
            }
        }
        std::cin >> s;
        n = (i64)s.size();
        std::cout << go(0, 0) << '\n';
    }

    return 0;
}
