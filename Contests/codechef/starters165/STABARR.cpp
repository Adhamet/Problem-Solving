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
        int n;
        cin >> n;
        vector<int> a(n);
        set<pair<int, int>> st;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i > 0 && a[i] > a[i - 1]) {
                st.insert({a[i], i});
            }
        }
        
        int cnt = 0;
        while (!st.empty()) {
            set<pair<int, int>> tmp;
            for (auto [val, idx] : st) {
                if (idx > 0 && val > a[idx - 1]) {
                    tmp.insert({val, idx - 1});
                }
            }
            
            if (tmp.empty()) {
                break;
            }
            
            st = tmp;
            cnt++;
        }
        
        cout << cnt << el;
    }
    
    return 0;
}
