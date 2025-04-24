#include <bits/stdc++.h>
using namespace std;
using ull = unsigned int;
#define int long long
#define el '\n'

int fastpow(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b & 1) result *= a;
        a *= a;
        b >>= 1;
    }

    return result;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;

        bool aExists = (t.find('a') != string::npos);
        if (aExists) {
            if ((int)t.size() > 1) cout << -1 << el;
            else cout << 1 << el;
        } else {
            cout << fastpow(2, (int)s.size()) << el;
        }
    }

    return 0;
}