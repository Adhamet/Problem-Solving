#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    const int N = 3;
    vector<pair<int, int>> rects(N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &rects[i].first, &rects[i].second);
    }
    long long area = 0;
    for (pair<int, int> p : rects) { area += p.first * p.second; }

    int len = 1;
    while (len * len < area) { len++; }

    if (len * len != area) {
        printf("-1");
        return 0;
    }

    for (int rotate_mask = 0; rotate_mask < (1 << N); rotate_mask++) {
        vector<string> grid(len, string(len, 'Z'));
        int num_placed = 0;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (grid[i][j] == 'Z') {
                    if (num_placed == N) {
                        goto outer;
                    }

                    int w = rects[num_placed].first;
                    int h = rects[num_placed].second;

                    if (rotate_mask & (1 << num_placed)) {
                        swap(w, h);
                    }

                    for (int r = i; r < i + h; r++) {
                        for (int c = j; c < j + w; c++) {
                            if (r >= len || c >= len || grid[r][c] != 'Z') {
                                goto outer;
                            }
                            grid[r][c] = num_placed + 'A';
                        }
                    }

                    num_placed++;
                }
            }
        }

        assert(num_placed == N);
        printf("%d\n", len);
        for (int i = 0; i < len; i++) { printf("%s\n", grid[i].c_str()); }
        return 0;
    outer:;
    }
    printf("-1");
}
