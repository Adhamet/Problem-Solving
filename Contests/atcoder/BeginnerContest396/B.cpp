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

    std::stack<int> stk;
    for (int i = 0; i < 100; i++) stk.push(0);

    int q;  std::cin >> q;
    while (q--) {
        int type;   std::cin >> type;
        if (type == 1) {
            int x;  std::cin >> x;
            stk.push(x);
        } else {    // type == 2
            std::cout << stk.top() << '\n';
            stk.pop();
        }
    }

    return 0;
}
