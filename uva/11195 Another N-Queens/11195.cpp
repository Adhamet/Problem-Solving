#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vector<vector<bool>> blocked;
vector<int> col, diag_pos, diag_neg;
int n, cnt;

void searchQueens(int r) {
    if (r == n) {
        cnt++;
        return;
    }

    for (int c = 0; c < n; c++) {
        if (blocked[r][c] || col[c] || diag_pos[r + c] || diag_neg[n - 1 - c + r]) continue;
        col[c] = diag_pos[r + c] = diag_neg[n - 1 - c + r] = 1;
        searchQueens(r + 1);
        col[c] = diag_pos[r + c] = diag_neg[n - 1 - c + r] = 0;
    }
}

int main()
{
  int i = 1;
    while (scanf("%d", &n) && n) {
        col.assign(n, 0);
        diag_pos.assign(2 * n - 1, 0);
        diag_neg.assign(2 * n - 1, 0);
        blocked.assign(n, vector<bool>(n));

        for (int r = 0; r < n; r++) {
            char row[n];
            scanf("%s", row);
            for (int c = 0; c < n; c++) {
                blocked[r][c] = (row[c] == '*');
            }
        }

        cnt = 0;
        searchQueens(0);
        printf("Case %d: %d\n", i++, cnt);
    }

    return 0;
}
