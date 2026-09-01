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

    // 1110
    // this means
    // take the contigous 1s put them all inside each other
    // up until that 0, the 0 included.
    // then we break

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::string s;
        std::cin >> s;

        std::deque<int> dq;
        for (int i = 1; i <= n;) {
            if (s[i-1] == '1') {
                int j = i;
                while (j < n && s[j-1] == '1') j++;
                // debug(j);
                for (int k = j; k >= i; k--) {
                    if (s[k-1] == '0')
                        dq.push_front(k);
                    else dq.push_front(k), dq.push_back(k);
                }
                while (!dq.empty()) {
                    std::cout << dq.front() << ' ';
                    dq.pop_front();
                }
                i = j + 1;
            } else {
                std::cout << i << ' ';
                i++;
            }
        }

        std::cout << '\n';
    }

    return 0;
}
