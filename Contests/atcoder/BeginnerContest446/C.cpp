#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, d;   std::cin >> n >> d;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];
        for (int i = 0; i < n; i++) std::cin >> b[i];

        MinHeap<std::pair<int, int>> pq;
        for (int i = 1; i <= n; i++) {
            pq.push({i + d, a[i-1]});
        }

        for (int i = 1; i <= n; i++) {
            int toUse = b[i-1];

            auto [ev, curEg] = pq.top();
            pq.pop();

            while (curEg < toUse) {
                toUse -= curEg;
                if (!pq.empty()) {
                    ev = pq.top().first;
                    curEg = pq.top().second;
                    pq.pop();
                }
            }
            if (toUse != 0 && curEg >= toUse) {
                curEg -= toUse;
            }

            if (curEg > 0 && ev > i) {
                pq.push({ev, curEg});
            }
        }

        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top().second;
            pq.pop();
        }

        std::cout << ans << '\n';
    }
    
    return 0;
}
