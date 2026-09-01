#include <bits/stdc++.h>

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

constexpr int MOD = (int)1e9;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    const int MXV = (int)1e6;
    std::vector<int> spf(MXV+2);
    std::iota(spf.begin(), spf.end(), 0);
    
    for (int i = 2; i <= MXV; i++) {
        if (spf[i] == i) {
            for (i64 j = 1LL * i * i; j <= MXV; j += i)
                if (spf[(int)j] == (int)j)
                    spf[(int)j] = i;
        }
    }

    auto factorize = [&](int x) -> std::vector<int> {
        std::vector<int> factors;
        while (x > 1) {
            int curSpf = spf[x];
            factors.push_back(spf[x]);
            while (x > 1 && spf[x] == curSpf)
                x /= spf[x];
        }
        return factors;
    };

    int n, startx, starty;
    std::cin >> n >> startx >> starty;
    startx--, starty--;
    i64 valx = 0, valy = 0;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (startx == i) valx = a[i];
        if (starty == i) valy = a[i];
    }
    
    if (startx == starty) return std::cout << 0 << '\n', 0;
    if (valx == 1 || valy == 1) return std::cout << -1, 0;
    if (std::gcd(valx, valy) > 1) return std::cout << valx + valy, 0;
    // debug("tst");
    
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    int m = (int)a.size();

    std::vector<std::vector<int>> g(MXV + 1);
    std::vector<std::vector<int>> factors(m);
    for (int i = 0; i < m; i++) {
        if (a[i] == valx) startx = i;
        if (a[i] == valy) starty = i;
        factors[i] = factorize(a[i]);
        for (int pf: factors[i]) {
            g[pf].push_back(i);
        }
    }

    MinHeap<std::pair<i64, int>> pq;
    pq.push({valx, startx});
    std::vector<char> visI(m, 0);
    std::vector<char> visP(MXV + 1, 0);

    bool reached = false;
    while (!pq.empty()) {
        auto [cost, idx] = pq.top();
        pq.pop();
        if (visI[idx]) continue;
        visI[idx] = true;

        if (idx == starty) {
            std::cout << cost - a[idx] << '\n';
            reached = true;
            break;
        }

        for (int pf: factors[idx]) {
            if (visP[pf]) continue;
            visP[pf] = 1;
            for (int j: g[pf]) if (!visI[j])
                pq.push({cost + 2 * a[j], j});
        } 
    }

    if (!reached) std::cout << -1 << '\n';
    return 0;
}
