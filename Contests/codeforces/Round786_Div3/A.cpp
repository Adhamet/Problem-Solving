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
        double x, y;
        cin >> x >> y;
        double z = (y / x);
        if (z != floor(z) || z == 0) cout << 0 << ' ' << 0 << el;
        else {
            cout << 1 << ' ' << z << el;
        }
    }

    return 0;
}