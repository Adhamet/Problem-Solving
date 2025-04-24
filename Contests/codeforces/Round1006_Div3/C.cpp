#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;

        if (x == 0) {
            for (int i = 0; i < n; ++i) cout << "0";
            cout << el;
            continue;
        }

        int mask = 1;
        while ((x & mask) != 0) mask <<= 1;

        int mMax = min(mask, n);
        int found = -1;
        for (int currM = mMax; currM > 0; --currM) {
            int orVal;
            if (currM == 0) orVal=0;
            else {
                int bits = 64 - __builtin_clzll(currM - 1);
                orVal = (1LL << bits) - 1;
            }

            if (orVal > x) continue;

            int required = (orVal < x)? 1: 0;
            if (currM + required <= n) {
                found = currM;
                break;
            }
        }

        if (found != -1) {
            for (int i = 0; i < found; ++i) cout << i << ' ';
            for (int i = found; i < n; ++i) cout << x << ' ';
            cout << el;
        } else {
            for (int i = 0; i < n; ++i) cout << x << ' ';
            cout << el;
        }
    }

    return 0;
}