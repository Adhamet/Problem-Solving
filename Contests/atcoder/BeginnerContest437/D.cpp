#include <algorithm>
#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

constexpr int MOD = 998244353;
class Z {
    int val = 0;

public:
    constexpr Z() = default;
    template<class T> constexpr Z(const T &v): val((MOD + v % MOD) % MOD) {}
    constexpr Z(const Z &z) = default;
    constexpr int operator()() const { return val; }
    constexpr Z pow(unsigned long long b) const {
        Z ans = 1;
        for (Z a = *this; b; b >>= 1, a *= a)
            if (b & 1) ans *= a;
        return ans;
    }
    constexpr Z inv() const { return pow(MOD - 2); }
    constexpr Z& operator += (Z a) { val += a.val; if (val >= MOD) val -= MOD; return *this; }
    constexpr Z& operator -= (Z a) { val -= a.val; if (val < 0) val += MOD; return *this; }
    constexpr Z& operator *= (Z a) { val = 1LL * val * a.val % MOD; return *this; }
    constexpr Z& operator /= (Z a) { return *this *= a.inv(); }
    friend constexpr Z operator + (Z a, Z b) { return a += b; }
    friend constexpr Z operator - (Z a, Z b) { return a -= b; }
    friend constexpr Z operator * (Z a, Z b) { return a *= b; }
    friend constexpr Z operator / (Z a, Z b) { return a /= b; }
    friend constexpr bool operator<(const Z &a, const Z &b) { return a.val < b.val; }
    friend constexpr bool operator>(const Z &a, const Z &b) { return a.val > b.val; }
    friend constexpr bool operator<=(const Z &a, const Z &b) { return a.val <= b.val; }
    friend constexpr bool operator>=(const Z &a, const Z &b) { return a.val >= b.val; }
    friend constexpr bool operator==(const Z &a, const Z &b) { return a.val == b.val; }
    friend constexpr bool operator!=(const Z &a, const Z &b) { return a.val != b.val; }
    friend std::ostream& operator<<(std::ostream &os, Z a) {
        return os << a();
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<Z> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        a[i] = Z(x);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x;
        b[i] = Z(x);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::vector<Z> prefB(m), suffB(m);
    prefB[0] = b[0];
    for (int i = 1; i < m; i++) prefB[i] = prefB[i-1] + b[i]();
    suffB[m-1] = b[m-1];
    for (int i = m-2; i >= 0; i--) suffB[i] = suffB[i+1] + b[i]();

    Z ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = std::upper_bound(b.begin(), b.end(), a[i]()) - b.begin() - 1;
        if (idx >= 0) ans += Z((i64)(idx + 1) * a[i]() - prefB[idx]);
        if (idx + 1 < m) ans += Z(suffB[idx + 1] - (i64)(m - idx - 1)*a[i]());
    }

    return std::cout << ans(), 0;
}
