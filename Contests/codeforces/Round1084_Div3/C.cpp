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

    // First thing is there must be two adjacent equal chars
    // if no then NO
    // every adjacent equal chars take care of themselves
    // every adjacent equal chars should be inside equal chars
    // two pointers simulation?
    // set each adjacent equal chars to **, then two pointers s.t.
    // condition is satisfied a[l] == a[r], turning everything to **
    // repeat for rest adjacent chars.
    int t;  std::cin >> t;
    while (t--) {
        int n;
        std::string s;
        std::cin >> n >> s;

        bool acc = false;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                acc = true;
                break;
            }
        }

        if (!acc) {
            std::cout << "NO\n";
            continue;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] != '*' && s[i] == s[i+1]) {
                s[i] = '*', s[i+1] = '*';
                int l = i-1, r = i+2;
                while (l >= 0 && r < n) {
                    while (l >= 0 && s[l] == '*') l--;
                    while (r < n && s[r] == '*') r++;
                    if (s[l] != s[r]) break;
                    s[l] = '*';
                    s[r] = '*';
                    l--, r++;
                }
            }
        }

        acc = true;
        for (int i = 0; i < n; i++) if (s[i] != '*') acc = false;
        std::cout << (acc? "YES\n": "NO\n");
    }



    return 0;
}
