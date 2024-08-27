#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
#endif

    int t,grid[8][8];

    scanf("%d",&t);
    while(t--) {
        int n;  scanf("%d", &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &grid[i][j]);

        int choices[8] = {0,1,2,3,4,5,6,7};
        int mn = 1e9;
        do {
            int sum = 0;
            for(int i = 0; i < n; i++) sum += grid[i][choices[i]];
            mn = min(mn,sum);
        } while (next_permutation(choices, choices+n));
        printf("%d\n", mn);
    }

    return 0;
}
