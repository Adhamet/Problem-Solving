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

    int n;
    std::string s;
    std::cin >> n >> s;

    i64 opPref = 0, cSuff = 0;
    for (char c: s) if (c == ')') {
        cSuff++;
    }

    i64 ans = cSuff;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') opPref++;
        else if (s[i] == ')') cSuff--;
        ans = std::min(ans, opPref + cSuff);
    }

    return std::cout << 2 * ans, 0;
}
