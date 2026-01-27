#include <bits/stdc++.h>

using i64 = long long;

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::map<int,int> freq;

    for (int i = 0; i < n*n; i++) {
        int x;  std::cin >> x;
        freq[x]++;
    }

    std::vector<std::vector<int>> g(n, std::vector<int>(n));
    if (n & 1) {
        int i = 0, j = 0;
        // EVEN STUFF
        for (auto &x: freq) {
            while (x.second >= 4 && i < (n/2)) {
                g[i][j] = g[n-i-1][j] = x.first;
                g[i][n-j-1] = g[n-i-1][n-j-1] = x.first;
                x.second -= 4;
                ++j;
                if (j >= n/2) j = 0, i++;
            }
            if (i >= n/2) break;
        }
        if (i < n/2) return std::cout << "NO\n", 0;

        // ODD ROWS
        int row = 0, k = n/2;
        for (auto &x: freq) {
            while (x.second >= 2 && row < n/2) {
                g[row][k] = g[n-row-1][k] = x.first;
                x.second -= 2;
                row++;
            }
            if (row >= n/2) break;
        }
        if (row < k) return std::cout << "NO\n", 0;

        // ODD COLS
        int col = 0;
        for (auto &x: freq) {
            while (x.second >= 2 && col < n/2) {
                g[k][col] = g[k][n-col-1] = x.first;
                x.second -= 2;
                col++;
            }
            if (col >= n/2) break;
        }
        if (col < n/2) return std::cout << "NO\n", 0;

        // FINALE
        int val = -1;
        for (auto &x: freq) {
            if (x.second > 0) {
                val = x.first;
                break;
            }
        }
        if (val == -1) return std::cout << "NO\n", 0;
        g[k][k] = val;


        std::cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << g[i][j] << ' ';
            }
            std::cout << '\n';
        }
    } else {
        bool buggedOut = false;

        int i = 0, j = 0;
        for (auto x: freq) {
            if (x.second % 4 != 0) {
                buggedOut = true;
                break;
            }

            int cnt = x.second;
            while (cnt >= 4) {
                if (i >= n/2) break;

                g[i][j] = g[n-i-1][j] = x.first;
                g[i][n-j-1] = g[n-i-1][n-j-1] = x.first;

                cnt -= 4;
                j++;
                if (j >= n/2) j = 0, i++;
            }
            if (i >= (n/2)) break;
        }

        if (buggedOut) std::cout << "NO\n";
        else {
            std::cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    std::cout << g[i][j] << ' ';
                }
                std::cout << '\n';
            }
        }
    }

    return 0;
}
