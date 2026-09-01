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

    int n;  std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::unordered_map<i64, int> lst;
    lst[0] = -1;

    i64 accu = 0;
    int moves = 0, lstClear = -1;
    for (int i = 0; i < n; i++) {
        accu += a[i];
        if (lst.count(accu) && lst[accu] >= lstClear) {
            moves++;
            lstClear = i;
            lst.clear();
            lst[0] = i;
            accu = a[i];
        }
        lst[accu] = i;
    }

    return std::cout << moves, 0;
}
