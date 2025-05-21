#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    unordered_set<int> acceptable;
    for (int i = 0, x = 3; x <= (8e6); ++i, x += 4) acceptable.insert(x);

    while (t--) {
        int n;
        cin >> n;
        
        if (!acceptable.count(n)) {
            cout << -1 << el;
            continue;
        }

        for (int i = 1; i <= (2*n) - 1; ++i) cout << i << ' ' << i + 1 << el;
        cout << el;
    }

    return 0;
}