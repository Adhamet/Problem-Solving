#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

const int n = 8;
int row[9];
bool isSafe(int c, int r) {
    for(int prev = 1; prev < c; prev++) {
        if (row[prev] == r || abs(row[prev] - r) == abs(prev - c))
            return false;
    }
    return true;
};

int main()
{
    adhamet;

    int t;  cin >> t;
    while(t--) {
        int x,y;    cin >> x >> y;

        memset(row, 0, sizeof row);
        int lineCounter = 0;

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        function<void(int)> search = [&](int col) {
            if(col == n+1) {
                if(row[y] == x) {
                    printf("%2d      %d", ++lineCounter, row[1]);
                    for(int j = 2; j <= 8; j++) printf(" %d", row[j]);
                    printf("\n");
                }
                return;
            }

            for(int r = 1; r <= 8; r++) {
                if(!isSafe(col, r)) continue;
                row[col] = r;
                search(col + 1);
            }
        };

        search(1);

        if(t) printf("\n");
    }

    return 0;
}
