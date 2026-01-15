#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        i64 n, k;   std::cin >> n >> k;
        if (n == k) {
            std::cout << 0 << '\n';
            continue;
        }

        std::queue<std::pair<int,int>> q;
        std::unordered_set<int> vis;
        q.push({n,0});
        vis.insert(n);

        int ans = -1;
        while (!q.empty()) {
            auto [x,t] = q.front();
            q.pop();

            if (x==k) {
                ans = t;
                break;
            }
            if (x < k) continue;

            i64 a = x/2, b=x-a;
            if (vis.insert(a).second) q.push({a, t+1});
            if (vis.insert(b).second) q.push({b, t+1});
        }

        std::cout << ans << '\n';
    }

    return 0;
}
