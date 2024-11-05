#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define int long long

const int MAXN = 1e3+9;
int n, m, x, y;
int dots[MAXN] = {0}, mem[MAXN][MAXN][3];

int solve(int col, int width, int last) {
    if (col == m) {
        if (width < x || width > y) return INT_MAX;
        return 0;
    }

    if (mem[col][width][last] != -1) return mem[col][width][last];

    int ddots = INT_MAX, hashes = INT_MAX;
    if (col == 0 || (last == 0 && width + 1 <= y) || (last == 1 && width >= x)) {
        ddots = n - dots[col] + solve(col + 1, (last == 0)? width + 1: 1, 0);
    }

    if (col == 0 || (last == 1 && width + 1 <= y) || (last == 0 && width >= x)) {
        hashes = dots[col] + solve(col + 1, (last == 1)? width + 1: 1, 1);
    }

    return mem[col][width][last] = min(ddots, hashes);
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    memset(mem, -1, sizeof(mem));
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == '.') dots[j] += 1;
        }
    }

    cout << solve(0, 0, 2) << el;
    return 0;
}
