#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> a(n, 0);

        std::priority_queue<std::pair<int,int>> pq;
        pq.push({n, 0});

        int val = 1;
        while (!pq.empty()) {
            auto node = pq.top();   pq.pop();
            int len = node.first, start = -node.second;
            int end = start + len - 1;

            int idx = -1;
            if (len & 1) idx = (start+end)/2;
            else idx = (start+end-1)/2;
            a[idx] = val++;
        
            if (idx > start) pq.push({idx-start, -start});
            if (idx < end) pq.push({end-idx, -(idx+1)});
        }

        for (int i = 0; i < n; i++) std:: cout << a[i] << ' ';
        std::cout << '\n';
    }

    return 0;
}
