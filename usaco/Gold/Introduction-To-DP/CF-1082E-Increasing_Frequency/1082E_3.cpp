#include <bits/stdc++.h>

using i64 = long long;

constexpr int MXN = (int)5e5+5;

int a[MXN], c;
int cnt[2][MXN], mx[2][MXN];

int dc(int L, int R) {
    if (L > R) return 0;
    if (L == R) return (a[L] != c);

    int md = (L + R) >> 1, ans = 0;

    // left
    for (int i = md; i >= L; i--) {
        int x = a[i];
        cnt[0][x]++;
        mx[0][x] = std::max(mx[0][x], cnt[0][x] - cnt[0][c]);
    }
    // right
    for (int i = md + 1; i <= R; i++) {
        int x = a[i];
        cnt[1][x]++;
        mx[1][x] = std::max(mx[1][x], cnt[1][x] - cnt[1][c]);
    }

    // crossing
    for (int i = L; i <= R; i++)
        ans = std::max(ans, mx[0][a[i]] + mx[1][a[i]]);

    // reset
    for (int i = L; i <= R; i++)
        mx[0][a[i]] = mx[1][a[i]] = cnt[0][a[i]] = cnt[1][a[i]] = 0;

    return std::max({ans, dc(L, md), dc(md + 1, R)});
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n, cntC = 0;  std::cin >> n >> c;
    for (int i = 0; i < n; i++)
        std::cin >> a[i], cntC += (a[i] == c);

    return std::cout << cntC + dc(0, n-1), 0;
}
