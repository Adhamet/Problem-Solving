#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;


const int MXN = (int)1e6 + 1;
int spf[MXN];

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    // If sorted beforehand, automatic bob win.
    // any prime number cant be used
    // perfect numbers decompose to the 1 prime, useless, 
    //
    // let us prime factorize number x
    // if cnt of primes > 1, Alice wins,
    // else if (cnt of 1 prime == 1) then its a prime, no.
    // else if (cnt of 1 prime > 1) then its a perfect num, also no
    //
    // in other words if cnt of primes > 1, Alice Wins,
    // else Bob Wins,
    // 
    // Proof why cnt of primes > 1, Alice always wins
    // assume a number is built from different primes 
    // and x,y prime factors of that number s.t. x != y:
    // at some-point of decomposing the number, we could put
    // a multiple of y before a multiple of x
    // for visualization: assume number = 2 * 2 * 2 * 3
    // we could take num = [3] x [2 * 2 * 2]
    // 
    // It is also a given fact that if its only 1 prime factor & 1 of it exists
    // then its a prime, nothing happens as it doesn't decompose further
    //
    // Applying the same Proof above to (only 1 prime-factor & cnt of it > 1)
    // then we will end up with just that prime repeated cnt times.
    //
    // so [3] x [2 * 2 * 2] at the end will be
    // [3] [2] [2] [2], no further possible decompositions
    // missing test-case mentioned below

    for (int i = 1; i < MXN; i++)
        spf[i] = i;
    for (int i = 2; i * i < MXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MXN; j += i) {
                spf[j] = i;
            }
        }
    }

    std::vector<std::pair<int,int>> factors;
    auto factorize = [&](int x) {
        factors.clear();
        while (x > 1) {
            int p = spf[x];
            int cnt = 0;

            while (x % p == 0) {
                x /= p;
                cnt++;
            }

            factors.push_back({p, cnt});
        }
    };
      

    int t;  std::cin >> t;
    while (t--) {
        int n;  std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        if (is_sorted(a.begin(), a.end())) {
            std::cout << "Bob\n";
            continue;
        }

        bool AliceWins = false;
        for (int i = 0; i < n; i++) {
            factorize(a[i]);
            if ((int)factors.size() > 1) {
                AliceWins = true;
                break;
            } else {
                // missing case:
                // if a[i] is perfect & a[i+1] is perfect,
                // you need to make sure a[i]'s prime is bigger than a[i+1]'s.
                if (i + 1 < n && spf[a[i+1]] < spf[a[i]]) {
                    AliceWins = true;
                }
            }
        }

        if (!AliceWins) {

        }

        std::cout << (AliceWins? "Alice\n": "Bob\n");
    }
    

    return 0;
}

