#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

// void setIO(string name = "") {
//     if (name.size()) {
//         freopen((name+".in").c_str(), "r", stdin);
//         freopen((name+".out").c_str(), "w", stdout);    
//     }
// }

int main()
{
    adhamet;
    // setIO("blist");

    int n;  // cin >> n;
    n = 8;
    
    vector<vector<bool>> blocked(n, vector<bool>(n));
    for(int r = 0; r < n; r++) {
        string row;     cin >> row;
        for(int c = 0; c < n; c++) { 
            blocked[r][c] = (row[c] == '*');
        }
    }

    int cnt = 0;


    vector<bool> col(n);
    vector<bool> diag_pos(2*n-1);
    vector<bool> diag_neg(2*n-1);
    function<void(int)> searchQueens = [&](int r) {
        if(r == n) {
            cnt++;
            return;
        }

        for(int c = 0; c < n; c++) {
            if(blocked[r][c] || col[c] || diag_pos[r+c] || diag_neg[n-1-c+r]) continue;
            col[c] = diag_pos[r+c] = diag_neg[n-1-c+r] = 1;
            searchQueens(r+1);
            col[c] = diag_pos[r+c] = diag_neg[n-1-c+r] = 0;
        }
    };

    searchQueens(0);
    cout << cnt;

    return 0;
}
