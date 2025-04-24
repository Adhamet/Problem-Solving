#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int xa, ya, xb, yb, xf, yf;
        cin >> xa >> ya >> xb >> yb >> xf >> yf;
        
        int dx = abs(xa - xb);
        int dy = abs(ya - yb);
        int ans = dx + dy;
        if ((xa == xb && xb == xf && yf > min(ya, yb) && yf < max(ya, yb)) ||
            (ya == yb && yb == yf && xf > min(xa, xb) && xf < max(xa, xb))) {
            ans += 2;
        }
        
        cout << ans << el;
    }

    return 0;
}