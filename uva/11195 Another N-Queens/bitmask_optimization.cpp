#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
void setIO(string name = "");
void redirectIO();

int n, ans = 0;
vector<int> board;
void n_queens(int row, int COL, int PD, int ND) {
    if(row == n) {
        ans++;
        return;
    }

    int validPos = ~(COL | PD | ND | board[row]); // check for available positions for queen
    validPos &= ((1<<n) - 1); // to remove any 1s beyond the row's size

    while(validPos) {
        int pos = (validPos & ~validPos); // twos compliment.
        n_queens(row+1, COL | pos, (PD | pos) << 1, (ND | pos) >> 1);
        validPos ^= pos;
    }
}

int main()
{
//    redirectIO();
    adhamet;

    int lines = 0;
    while(true) {
        cin >> n;
        if(!n) break;

        ans = 0;
        board = vector<int>(n);
        for(int i = 0; i < n; i++) {
            board[i] = 0;
            for(int j = 1; j < (1<<n); j<<=1) {
                char c;     cin >> c;
                if(c == '*') board[i] |= j;
            }
        }

        n_queens(0,0,0,0);
        cout << "Case " << ++lines << ": ";
        cout << ans << el;
    }

    return 0;
}

void redirectIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
#endif
}
