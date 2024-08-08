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

int solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            a[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            b[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < (n/2) + 1; i++) {
        for (int j = 0; j < (m/2) + 1; j++) {
            for (pi diag = {i+1, j+1}; diag.F < n && diag.S < m; diag.F++, diag.S++) {
    
                pair<pi,pi> choices[3];
                choices[0] = { { a[i][j], a[diag.F][diag.S] }, { a[i][diag.S], a[diag.F][j] } };
                choices[1] = { { (a[i][j]+1) % 3, (a[diag.F][diag.S]+1) % 3 }, { (a[i][diag.S]+2) % 3, (a[diag.F][j]+2) % 3 } };
                choices[2] = { { (a[i][j]+2) % 3, (a[diag.F][diag.S]+2) % 3 }, { (a[i][diag.S]+1) % 3, (a[diag.F][j]+1) % 3 } };
    
                bool reachable = false;
                for (int j = 0; j < 3; j++) {
                    if (b[i][j] == choices[i].F.F && b[diag.F][diag.S] == choices[i].F.S && b[i][diag.S] == choices[i].S.F && b[diag.F][j] == choices[i].S.S) {
                        reachable = true;
                        break;
                    }
                }
    
                if (!reachable) {
                    return cout << "NO\n", 0;
                }
            }
        }
    }
    return cout << "YES\n", 0;
}

int main()	{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
