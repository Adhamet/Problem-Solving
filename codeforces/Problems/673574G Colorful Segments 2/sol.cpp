#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

constexpr int MOD = (int)998244353;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    // I think its a standard cnting problem?
    // For the first segment we give it all K as possible choices
    // now, let us assume we have one overlap
    // 1 -> 3
    // 2 -> 4
    // the first segment now well, it gets K choicces, no the 2nd
    // one can get anyone except the one chosen by the first segment
    // making it K - 1, (K - number of overlaps)
    // 1 -> 5
    // 2 -> 6
    // 3 -> 7
    // Answer here would be K * (K - 1) * (K - 2)
    // 1 -> 2
    // 3 -> 4
    // no overlaps: K * K
    // 1 -> 3
    // 3 -> 4
    // 4 -> 7
    // 5 -> 8
    // Answer here would be K * (K - 1) * (K - 1) * (K - 1)
    // so as you go deeper into the overlap, subtract 1 from K.
    
    int t;  std::cin >> t;
    while (t--) {
        int n;
        i64 k;
        std::cin >> n >> k;
        std::vector<std::pair<int,int>> seg(n);
        for (int i = 0; i < n; i++) {
            std::cin >> seg[i].first >> seg[i].second;
        }

        std::sort(seg.begin(), seg.end());

        i64 ans = 1;
        MinHeap<int> pq;
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top() < seg[i].first) {
                pq.pop();
            }

            i64 openColors = k - (int)pq.size();
            if (openColors <= 0) {
                ans = 0;
                break;
            }

            ans = ans * openColors % MOD;
            pq.push(seg[i].second);
        }

        std::cout << ans << '\n';
    }

    return 0;
}
