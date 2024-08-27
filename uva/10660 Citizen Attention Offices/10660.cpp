#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
#endif
    int t;  scanf("%d", &t);
    while (t--) {
        int n;  scanf("%d", &n);
        vector<vector<int>> areas(n, vector<int>(3));
        for (int i = 0; i < n; i++) scanf("%d %d %d", &areas[i][0], &areas[i][1], &areas[i][2]);

        vector<int> offices(5, 0);
        int minSum = INT_MAX;
        for (int i = 0; i < 25; i++) {
            for (int j = i+1; j < 25; j++) {
                for (int k = j+1; k < 25; k++) {
                    for (int l = k+1; l < 25; l++) {
                        for (int m = l+1; m < 25; m++) {
                            int sum = 0;
                            for (const auto& area : areas) {
                                int dist = INT_MAX;
                                for(int office : {i,j,k,l,m})
                                    dist = min(abs(office/5-area[0])+abs(office%5-area[1]),dist);
                                sum += dist * area[2];
                            }
                            if (sum < minSum) {
                                minSum = sum;
                                offices = {i, j, k, l, m};
                            }
                        }
                    }
                }
            }
        }

        sort(offices.begin(), offices.end());
        for (int i = 0; i < 5; i++) {
            printf("%d",offices[i]);
            if (i < 4) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
