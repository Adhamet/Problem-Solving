#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

constexpr int MXN = (int)1e5 + 5; 
std::vector<int> g[MXN];
int init[MXN], goal[MXN];
std::vector<int> nodes;
int ans = 0;

void dfs(int u, int p, int flipCur, int flipNext) {
    int curVal = init[u] ^ flipCur;
    if (curVal != goal[u]) {
        ans++;
        nodes.push_back(u);
        flipCur ^= 1;
    }

    for (int v: g[u]) if (v != p) dfs(v, u, flipNext, flipCur);
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    
    int n;  std::cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;   std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < n; i++) std::cin >> init[i];
    for (int i = 0; i < n; i++) std::cin >> goal[i];

    dfs(0, -1, 0, 0);

    std::cout << ans << '\n';
    for (int x: nodes) std::cout << x+1 << '\n';
    return 0;
}
