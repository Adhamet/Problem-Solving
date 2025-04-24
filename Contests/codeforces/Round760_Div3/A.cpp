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
        vector<int> a(7);
        unordered_set<int> exist;
        for (int i = 0; i < 7; ++i) cin >> a[i], exist.insert(a[i]);

        if (exist.count(a[0] + a[1] + a[3])) {
            cout << a[0] << ' ' << a[1] << ' ' << a[3] << el;
        } else cout << a[0] << ' ' << a[1] << ' ' << a[2] << el;
    }
    
    return 0;
}