#include <bits/stdc++.h>
using namespace std;

#define i64 long long
const i64 MOD = 1000000007;
const i64 MODM1 = MOD - 1;

i64 modpow(i64 a, i64 b) {
    i64 res = 1 % MOD;
    a %= MOD;
    while (b) {
        if (b & 1) res = (__int128)res * a % MOD;
        a = (__int128)a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<i64> p(n), k(n);
    for (int i = 0; i < n; i++)
        cin >> p[i] >> k[i];

    // number of divisors
    i64 numDiv = 1;
    for (int i = 0; i < n; i++)
        numDiv = numDiv * (k[i] + 1) % MOD;

    // sum of divisors
    i64 sumDiv = 1;
    for (int i = 0; i < n; i++) {
        i64 num = (modpow(p[i], k[i] + 1) - 1 + MOD) % MOD;
        i64 den = modpow(p[i] - 1, MOD - 2);
        sumDiv = sumDiv * num % MOD * den % MOD;
    }

    // product of divisors
    i64 prodDiv = 1;
    i64 divCnt = 1; // divisors so far

    for (int i = 0; i < n; i++) {
        // raise existing product
        prodDiv = modpow(prodDiv, k[i] + 1);

        // multiply contribution of p[i]
        i64 exp = (k[i] * (k[i] + 1) / 2) % MODM1;
        exp = exp * divCnt % MODM1;
        prodDiv = prodDiv * modpow(p[i], exp) % MOD;

        // update divisor count
        divCnt = divCnt * (k[i] + 1) % MODM1;
    }

    cout << numDiv << " " << sumDiv << " " << prodDiv << '\n';
    return 0;
}

