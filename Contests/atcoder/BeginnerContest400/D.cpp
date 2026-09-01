#include <bits/stdc++.h>

// -- Don't use with doubles -----------
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
// -------------------------------------
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
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, m;  std::cin >> n >> m;
    std::vector<std::string> g(n);
    for (int i = 0; i < n; i++) std::cin >> g[i];

    int sx, sy, ex, ey;  std::cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;

    std::vector dist(n, std::vector<int>(m, (int)1e9));
    MinHeap<std::tuple<int,int,int>> pq;

    dist[sx][sy] = 0;
    pq.push({0, sx, sy});

    bool found = false;
    while (!pq.empty()) {
        auto [kicks, r, c] = pq.top(); pq.pop();

        if (kicks > dist[r][c]) continue;
        if (r == ex && c == ey) {
            found = true;
            std::cout << kicks;
            break;
        }

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] == '.') {
                if (dist[nr][nc] > kicks) {
                    dist[nr][nc] = kicks;
                    pq.push({kicks, nr, nc});
                }
            }
        }

        for (int d = 0; d < 4; d++) {
            for (int step = 1; step <= 2; step++) {
                int nr = r + step * dr[d], nc = c + step * dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (dist[nr][nc] > kicks + 1) {
                        dist[nr][nc] = kicks + 1;
                        pq.push({kicks + 1, nr, nc});
                    }
                }
            }
        }
    }

    if (!found) std::cout << -1;
    return 0;
}
