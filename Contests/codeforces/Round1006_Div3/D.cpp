#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        if (x == 0) {
            for (int i = 0; i < n; ++i) cout << 0;
            cout << el;
            continue;
        }
        
        int m = 1;
        while ((x & (m - 1)) == (m - 1)) {
            m <<= 1;
        }
        
        if (x == m - 1) {
            if (n >= m) {
                for (int i = 0; i < m; ++i) cout << i << " ";
                for (int i = m; i < n; ++i) cout << 0 << " ";
            } else for (int i = 0; i < n; ++i) cout << i << " ";
        } else {
            cout << x << " ";
            int count = 1;
            for (int i = 0; i < m && count < n; ++i) {
                if (i != x) {
                    cout << i << " ";
                    count++;
                }
            }

            while (count < n) {
                cout << 0 << " ";
                count++;
            }
        }

        cout << el;
    }
    
    return 0;
}