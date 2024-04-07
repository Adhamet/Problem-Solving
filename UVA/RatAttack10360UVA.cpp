#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("errors.txt", "w", stderr);
    #endif


    int d, n, x, y, p;
    int killed[1024][1024];

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &d);
        scanf("%d", &n);
        for (int i = 0; i < 1024; i++)
            for (int j = 0; j < 1024; j++)
                killed[i][j] = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &x, &y, &p);
            for (int j = x - d; j <= x + d; j++) {
                if (j < 0 || j >= 1024)
                    continue;

                for (int k = y - d; k <= y + d; k++) {
                    if (k < 0 || k >= 1024)
                        continue;

                    killed[j][k] += p;
                }
            }
        }

        int mx = 0;
        for (int i = 0; i < 1024; i++) {
            for (int j = 0; j < 1024; j++) {
                if (killed[i][j] > mx) {
                    x = i, y = j;
                    mx = killed[i][j];
                }
            }
        }

        printf("%d %d %d\n", x, y, mx);
    }


    return 0;
}
