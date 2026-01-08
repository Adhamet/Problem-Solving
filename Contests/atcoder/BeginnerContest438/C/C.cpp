#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::vector<int> vec;
    vec.reserve(n+5);
    for (int i = 0; i < n; i++) {
        int x;  std::cin >> x;
        vec.push_back(x);
        if ((int)vec.size() >= 3) {
            int j = (int)vec.size() - 1;

            if (vec[j] == vec[j-1])
                if (vec[j] == vec[j-2])
                    if (vec[j] == vec[j-3])
                        for (int k = 0; k < 4; k++)
                            vec.pop_back();
        }
    }

    return std::cout << (int)vec.size(), 0;
}
