#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n,k;   std::cin >> n >> k;
    std::vector<std::vector<int>> startIdx(202);
    std::vector<std::array<int, 2>> seg(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> seg[i][0] >> seg[i][1];
        startIdx[seg[i][0]].push_back(i);
    }

    std::vector<int> ans;
    std::vector<bool> vis(n + 1, false);
    std::priority_queue<std::pair<int, int>> pq;

    for (int i = 1; i <= 201; i++) {
        for (auto idx : startIdx[i]) {
            if (!vis[idx]) {
                pq.push({seg[idx][1], idx});
            }
        }
        
        while (!pq.empty() && pq.top().first < i) pq.pop();

        std::vector<std::pair<int, int>> tmp;
        int existingCnt = 0;

        while (!pq.empty()) {
            auto [end, idx] = pq.top();
            pq.pop();
            if (!vis[idx] && end >= i) {
                tmp.push_back({end, idx});
                existingCnt++;
            }
        }
        for (auto& p : tmp) pq.push(p);

        while (existingCnt > k) {
            auto [end, idx] = pq.top();
            pq.pop();
            if (!vis[idx]) {
                vis[idx] = true;
                ans.push_back(idx);
                existingCnt--;
            }
        }
    }

    std::cout << (int)ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); i++) std::cout << ans[i] << ' ';

    return 0;
}
