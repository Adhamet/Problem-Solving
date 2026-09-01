#include <bits/stdc++.h>

using i64 = long long;

const int MXN = 2e5 + 5;

int n;
int a[MXN];

i64 mem[MXN][21][2];
bool vis[MXN][21][2];
i64 go(int idx, int k, int state) {
    if (idx == n) return 0;

    i64 &ret = mem[idx][k][state];
    if (vis[idx][k][state]) return ret;
    vis[idx][k][state] = 1;
    
    i64 v = (state == 0)? a[idx]: -a[idx];
    ret = v;

    ret = std::max(ret, v + go(idx + 1, k, state)); // keep going
    // or flip
    if (state == 0 && k)
        ret = std::max(ret, v + go(idx + 1, k - 1, 1));
    else ret = std::max(ret, v + go(idx + 1, k, 0));

    return ret;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int k;   std::cin >> n >> k;
    for (int i = 0; i < n; i++) std::cin >> a[i];

    i64 ans = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        ans = std::max(ans, go(i, k, 0));
        if (k) ans = std::max(ans, go(i, k - 1, 1));
    }

    return std::cout << ans << '\n', 0;
}

