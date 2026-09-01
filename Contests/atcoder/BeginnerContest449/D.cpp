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

    // max(|x|, |y|) is even then black
    // max(|x|, |y|) is odd then white
    // max(4, 1), max(4, 2), max(4, 3) all black
    // startin from 4,4 it changes black and white
    // so up until U, its half and half.
    // so its (|L| - |D\) gives us whats below 4 which will
    // all be painted be black which is determined by 4 itself
    //
    // |L| matters only when |L| > |di| and |L| < |ui|
    // where are di, ui are just a part of the full D, U
    // at those cases if it is even then |L| then
    // ans += |L| - |di|
    // ans += |L| - |ui| - 1
    // actually it would rather just be ui - di + 1
    // then
    // ans += (|ui + 1| - |L| + 1) / 2;
    // ans += (|di - 1| - |L| + 1) / 2;
    // 
    // range is 2x10^6, do it for each column? yes.
    
    i64 ans = 0;
    int L, R, D, U; std::cin >> L >> R >> D >> U;

    for (int i = L; i <= R; i++) {
        int cL = std::abs(i);
        
        int di = std::max(D, -cL);
        int ui = std::min(U, cL);

        if (std::abs(i) % 2 == 0) {
            if (di <= ui) ans += (ui - di + 1);
        }
        
        int upStart = std::max(D, cL + 1), upEnd = U;
        if (upStart <= upEnd)
            ans += (upEnd - upStart + 1) / 2 + ((upStart % 2 == 0 && upEnd % 2 == 0) ? 1 : 0);
        int dnStart = D, dnEnd = std::min(U, -cL - 1);
        if (dnStart <= dnEnd)
            ans += (dnEnd - dnStart + 1) / 2 + ((dnStart % 2 == 0 && dnEnd % 2 == 0) ? 1 : 0);
    }

    return std::cout << ans, 0;
}
