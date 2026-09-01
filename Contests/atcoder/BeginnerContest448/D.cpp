#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

constexpr int MXN = 2e5+5;

struct SplitMix64 {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int a[MXN];
std::vector<int> g[MXN];
std::vector<char> ans(MXN, 0);
std::unordered_map<int, int, SplitMix64> vis;

void dfs(int u, int p, bool yesForAll) {
    bool added = false;
    if (yesForAll) ans[u] = 1;
    else {
        if (vis[a[u]]) ans[u] = 1, yesForAll = true;
        else vis[a[u]]++, added = true;
    }

    for (int v: g[u]) if (v != p)
        dfs(v, u, yesForAll);

    if (added) vis[a[u]]--;
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    // backtracking problem
    
    int n;  std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;   std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0,0,false);

    for (int i = 0; i < n; i++)
        std::cout << (ans[i]? "Yes\n": "No\n");
    return 0;
}
