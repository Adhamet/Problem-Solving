#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::string s;  std::cin >> s;

    int op = 0;
    for (int i = 0; i + 1 < (int)s.size();) {
        if ((i % 2 == 0) && s[i] == s[i + 1]) {
            s.erase(i + 1, 1);
            op++;
        } else {
            i++;
        }
    }

    if ((int)s.size() & 1) s.erase(s.end() - 1), op++;
    std::cout << op << '\n';
    std::cout << s;

    return 0;
}
