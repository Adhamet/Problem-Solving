#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int main()	{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
 
        vector<vector<ll>> a(n, vector<ll>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
 
        if (n == 1 && m == 1) {
            cout << -1 << el;
            continue;
        }
 
        vector<vector<int>> b(n, vector<int>(m));

        for (int j = 0; j < m; j++) {
           for (int i = 0; i < n; i++) {
                b[n - 1 - i][m - 1 - j] = a[i][j];
            }
        }

        if (n % 2 && m % 2) {
            if (m > 1) {
                swap(b[n / 2][m / 2], b[n / 2][m / 2 + 1]);
            } else {
                swap(b[n / 2][m / 2], b[n / 2 + 1][m / 2]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << b[i][j] << " ";
            }
            cout << el;
        }
    }

    return 0;
}
