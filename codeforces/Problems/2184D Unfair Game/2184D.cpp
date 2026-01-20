#include <bits/stdc++.h>

using i64 = long long;

int n, k, m;
i64 mem[52][102];

i64 go(int idx, int curMoves) {
    if (idx == m) return 0;

    i64 &ways = mem[idx][curMoves];
    if (~ways) return ways;
    ways = 0;

    if (curMoves + 1 <= k && idx + 1 < m)
        ways += go(idx + 1, curMoves + 1) + 1;
    if (curMoves + 2 <= k && idx + 1 < m)
        ways += go(idx + 1, curMoves + 2) + 1;
    return ways;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        for (int i = 0; i <= 50; i++)
            for (int j = 0; j <= 100; j++) 
                mem[i][j] = -1;

        std::cin >> n >> k;
        
        m = std::log2(n);
        if (k >= m + 1) n--;

        std::cout << std::max(n - go(0, 1) - 1, 0LL) << '\n';
    }

    return 0;
}
