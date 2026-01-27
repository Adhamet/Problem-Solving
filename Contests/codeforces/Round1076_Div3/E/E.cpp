#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    
    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> a(n);
        std::vector<bool> exists(n + 1, false);
        std::vector<int> uniq;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            if (!exists[a[i]]) {
                exists[a[i]] = true;
                uniq.push_back(a[i]);
            }
        }
        
        std::sort(uniq.begin(), uniq.end());
        
        std::vector<int> dist(n + 1, -1);
        std::queue<int> q;
        for (int x : uniq) {
            dist[x] = 1;
            q.push(x);
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int x: uniq) {
                if (x == 1) continue;
                if (u > n / x) break;
                
                int v = u * x;
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        
        for (int i = 1; i <= n; i++) std::cout << dist[i] << ' ';
        std::cout << '\n';
    }
    
    return 0;
}

