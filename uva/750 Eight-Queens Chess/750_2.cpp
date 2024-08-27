// Pruning The Search - Optimzing the recursion|back-tracking.
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

const int n = 8;
int x, y;
int input[8];
int rw[8], lrd[15], rld[15];
int lineCounter;

void search(int col) {
    if(col >= n && input[y] == x) {
        printf("%2d      %d", ++lineCounter, input[0] + 1);
        for(int j = 1; j < 8; j++) printf(" %d", input[j] + 1);
        printf("\n");
        return;
    }

    for(int r = 0; r < 8; r++) {
        if(rw[r] || lrd[r+col] || rld[n-1-col+r]) continue;

        input[col] = r;
        if(col == y && input[col] != x) continue;

        rw[r] = lrd[r+col] = rld[n-1-col+r] = 1;
        search(col + 1);
        rw[r] = lrd[r+col] = rld[n-1-col+r] = 0;
    }
};

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("errors.txt", "w", stderr);
    #endif
    adhamet;

    int t; cin >> t;
    while(t--) {
        cin >> x >> y;
        x--,y--;

        memset(input, 0, sizeof input);
        lineCounter = 0;

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        search(0);

        if(t) printf("\n");
    }

    return 0;
}
