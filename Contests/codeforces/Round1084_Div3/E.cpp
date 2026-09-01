#include <bits/stdc++.h>

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    // watchout, if sorted beforehand bob auto wins
    // any prime number cant be used
    // perfect squares get x==y, watchout
    // any even number can have 1 prime number(2) and a composite
    // meaning one extra number to divide,
    // or 
    //
    // let us prime factorize number x
    // if it has exacly two primes with each cnt 1, then we can make it done
    // if it has exactly two primes with one cnt > 1, then we can make 1 prime, 1 perfect sqr
    // if it has exactly two primes with both cnt > 1, two perfect sqrs
    // if it has more than two primes, 1 prime and 1 composite, or 2 composites
    // overcomplicated..
    //

    std::vector<bool> isPrime((int)1e6+2, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= (int)1e6; i++) if (isPrime[i]) {
        for (int j = i * i; j <= (int)1e6; j += i)
            isPrime[j] = false;
    }

      

    return 0;
}
