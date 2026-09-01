#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, 
                         tree_order_statistics_node_update>;

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

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<std::pair<i64,i64>> vec(n);
        for (int i = 0; i < n; i++) 
            std::cin >> vec[i].first >> vec[i].second;

        std::sort(vec.begin(), vec.end(), [](auto &A, auto &B) {
            return A.first < B.first;
        });

        i64 ans = 0;
        ordered_set<i64> os;
        for (int i = 0; i < n; i++) {
            os.insert(vec[i].second);
            ans += (int)os.size() - os.order_of_key(vec[i].second) - 1;
        }

        std::cout << ans << '\n';
    }

    return 0;
}
