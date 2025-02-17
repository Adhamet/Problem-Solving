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
        for (int &x : a) cin >> x;
        
        // Find rightmost positive
        int lastPos = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] > 0) {
                lastPos = i;
                break;
            }
        }
        
        if (lastPos == -1) {
            // All negatives - take the largest one
            int mx = *max_element(a.begin(), a.end());
            cout << -mx << '\n';
        } else {
            // Take all positives and negatives after lastPos
            long long coins = 0;
            for (int i = n - 1; i >= 0; --i) {
                if (a[i] > 0) coins += a[i];
                else if (i > lastPos) coins += -a[i];
            }
            cout << coins << '\n';
        }
    }

    return 0;
}