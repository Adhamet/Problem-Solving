#include <bits/stdc++.h>

using i64 = long long;

const int MXN = (int)1e3+5, MOD = (int)1e9+7;

i64 mem[MXN][MXN];
int n;

i64 addm(i64 x, i64 y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

i64 go(int idx, int k) {
    if (k < 0) return 0;
    if (idx == 0) return (k == 0);

    i64 &ret = mem[idx][k];
    if (~ret) return ret;
    ret = 0;

    for (int x = 0; x <= std::min(idx - 1, k); x++)
        ret = addm(ret, go(idx - 1, k - x));
 
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int k;
    std::cin >> n >> k;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            mem[i][j] = -1;

    return std::cout << go(n, k), 0;
}
