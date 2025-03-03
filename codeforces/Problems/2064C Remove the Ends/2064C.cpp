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
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        int lastNeg = 0;
        vector<int> negatives(n);
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] < 0) {
                negatives[i] = abs(a[i]) + lastNeg;
                lastNeg = negatives[i];
            }
        }

        int lastPos = 0;
        vector<int> positives(n);
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) {
                positives[i] = a[i] + lastPos;
                lastPos = positives[i];
            }
        }

        int ans = max(negatives[0], positives[n - 1]);
        for (int i = 0; i < n - 1; ++i) ans = max(ans, positives[i] + negatives[i + 1]);
        cout << ans << el;
    }

    return 0;
}