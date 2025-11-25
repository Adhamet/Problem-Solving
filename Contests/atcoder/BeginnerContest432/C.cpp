#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 extendedGCD(i64 a, i64 b, i64 &x, i64 &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    i64 x1, y1;
    i64 g = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    i64 X, Y;
    cin >> n >> X >> Y;

    vector<i64> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    // Diophantine: Z + (X-Y) q = X*A[i]
    // a=1, b=(X-Y)

    i64 b = X - Y;           // coefficient of q
    i64 g = llabs(b);        // gcd(1,b) = 1, but keep consistent

    // All Z must satisfy Z ≡ X*A[i] (mod |b|)
    i64 mod = llabs(b);
    i64 need = (mod == 0 ? X*A[0] : (X*A[0] % mod + mod) % mod);

    for (int i = 1; i < n; i++) {
        i64 r = (mod == 0 ? X*A[i] : (X*A[i] % mod + mod) % mod);
        if (r != need) {
            cout << -1 << "\n";
            return 0;
        }
    }

    // Each child i allows Z in:
    //   Z = X*A[i] - b*q   where 0 <= q <= A[i]
    // Thus Z ranges:
    //   Z_min[i] = X*A[i] - b*A[i]
    //   Z_max[i] = X*A[i]

    i64 globalL = -LLONG_MAX;
    i64 globalR = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        i64 Zmax = X * A[i];
        i64 Zmin = X * A[i] - b * A[i];

        if (Zmin > Zmax) swap(Zmin, Zmax);

        globalL = max(globalL, Zmin);
        globalR = min(globalR, Zmax);
    }

    if (globalL > globalR) {
        cout << -1 << "\n";
        return 0;
    }

    // Choose largest Z satisfying Z ≡ need (mod mod) within [globalL, globalR]
    i64 Z;
    if (mod == 0) {
        Z = globalR;   // any works
    } else {
        Z = globalR - ((globalR - need) % mod + mod) % mod;
        if (Z < globalL) {
            cout << -1 << "\n";
            return 0;
        }
    }

    // Compute q_i = (X*A[i] - Z)/(X-Y)
    i64 totalQ = 0;
    for (int i = 0; i < n; i++) {
        i64 num = X*A[i] - Z;
        if (b == 0) {
            if (num != 0) {
                cout << -1 << "\n";
                return 0;
            }
            continue;
        }
        if (num % b != 0) {
            cout << -1 << "\n";
            return 0;
        }
        i64 q = num / b;
        if (q < 0 || q > A[i]) {
            cout << -1 << "\n";
            return 0;
        }
        totalQ += q;
    }

    cout << totalQ << "\n";
    return 0;
}

