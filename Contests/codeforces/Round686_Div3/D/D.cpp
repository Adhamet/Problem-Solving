#include <bits/stdc++.h>

using i64 = long long;

struct SPF {
    int N;
    std::vector<int> spf;
    std::vector<int> primes;

    SPF(int n) : N(n) {}

    void computeSPF() {
        spf.resize(N+1);
        std::iota(spf.begin(), spf.end(), 0);
        for (int i = 2; i * i <= N; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= N; j += i)
                    if (spf[j] == j) spf[j] = i;
            }
        }
        for (int i = 2; i <= N; ++i) if (spf[i] == i) primes.push_back(i);
    }

    std::vector<std::pair<i64,int>> factorize(i64 x) {
        std::vector<std::pair<i64,int>> factors;
        for (int p : primes) {
            if ((i64)p * p > x) break;
            if (x % p == 0) {
                int cnt = 0;
                while (x % p == 0) { x /= p; ++cnt; }
                factors.emplace_back(p, cnt);
            }
        }
        if (x > 1) factors.emplace_back(x, 1);
        return factors;
    }
};

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    SPF spf(100000);
    spf.computeSPF();

    int t; std::cin >> t;
    while (t--) {
        i64 n;  std::cin >> n;

        auto f = spf.factorize(n);
        int idx = 0;
        for (int i = 1; i < (int)f.size(); ++i)
            if (f[i].second > f[idx].second) idx = i;

        i64 p = f[idx].first;
        int cnt = f[idx].second;

        std::cout << cnt << '\n';
        for (int i = 0; i < cnt - 1; ++i) std::cout << p << ' ';

        i64 x = n;
        for (int i = 0; i < cnt - 1; ++i) x /= p;
        std::cout << x << '\n';
    }

    return 0;
}

