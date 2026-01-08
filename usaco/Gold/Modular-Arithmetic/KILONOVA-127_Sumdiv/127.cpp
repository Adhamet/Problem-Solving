#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;


constexpr int MOD = (int)1e9+7;
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

std::vector<std::pair<i64, int>> factorize(i64 n) {
    std::vector<std::pair<i64, int>> factors;
    
    for (i64 i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            i64 cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt += 1;
            }
            factors.push_back({i, cnt});
        }
    }
    if (n > 1) factors.push_back({n, 1});

    return factors;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);

    i64 a, b;
    std::cin >> a >> b;

    if (a % MOD == 0) a /= MOD;
    
    std::vector<std::pair<i64, int>> factors = factorize(a);
    
    Z ans = 1;
    for (auto [p, e]: factors) {
        if (p % MOD == 1) ans *= e * Z(b) + 1;
        else ans *= (Z(p).pow(b % (MOD - 1) * e + 1) - 1) / (Z(p) - 1);
    }

    return std::cout << ans, 0;
}
