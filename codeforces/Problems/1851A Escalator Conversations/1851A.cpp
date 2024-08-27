#include <bits/stdc++.h>
using namespace std;

#define el '\n'

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k, H;
        cin >> n >> m >> k >> H;

        vector<int> h(n);
        for (auto &i: h) cin >> i;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int hDiff = abs(H - h[i]);
            bool canConverse = false;
            
            for (int stepDiff = 1; stepDiff < m; stepDiff++) {
                if (hDiff == stepDiff * k) {
                    canConverse = true;
                    break;
                }
            }
            
            if (canConverse) cnt++;
        }
        cout << cnt << el;
    }

    return 0;
}

