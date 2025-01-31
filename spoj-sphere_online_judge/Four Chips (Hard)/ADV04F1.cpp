#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    const int MAXN = 80;
	// 4D
    vector<vector<vector<vector<int>>>> dist(
        MAXN, vector<vector<vector<int>>>(
            MAXN, vector<vector<int>>(
                MAXN, vector<int>(MAXN, -1)
            )
        )
    );

    array<int, 4> s = {0, 1, 2, 3};
    dist[0][1][2][3] = 0;

    queue<array<int, 4>> q;
    q.push(s);

    while (!q.empty()) {
        array<int, 4> n = q.front();
        int distance = dist[n[0]][n[1]][n[2]][n[3]];
        q.pop();

        for (int i = 0; i < 4; ++i) {
            // Move left
            if ((i > 0 && n[i] - 1 != n[i - 1]) || (i == 0 && n[i] - 1 >= 0)) {
                array<int, 4> nn = n;
                nn[i] -= 1;
                sort(nn.begin(), nn.end());
                if (dist[nn[0]][nn[1]][nn[2]][nn[3]] == -1) {
                    dist[nn[0]][nn[1]][nn[2]][nn[3]] = distance + 1;
                    q.push(nn);
                }
            }
            // Move right
            if ((i < 3 && n[i] + 1 != n[i + 1]) || (i == 3 && n[i] + 1 < 70)) {
                array<int, 4> nn = n;
                nn[i] += 1;
                sort(nn.begin(), nn.end());
                if (dist[nn[0]][nn[1]][nn[2]][nn[3]] == -1) {
                    dist[nn[0]][nn[1]][nn[2]][nn[3]] = distance + 1;
                    q.push(nn);
                }
            }
        }

        // Symmetry moves
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (j == i) continue;

                int newi = n[j] + (n[j] - n[i]);
                if (newi < 0 || newi >= 70) continue;

                bool ok = true;
                for (int k = 0; k < 4; ++k) if (n[k] == newi) {
                    ok = false;
                    break;
                }

                if (!ok) continue;

                array<int, 4> nn = n;
                nn[i] = newi;
                sort(nn.begin(), nn.end());
                if (dist[nn[0]][nn[1]][nn[2]][nn[3]] == -1) {
                    dist[nn[0]][nn[1]][nn[2]][nn[3]] = distance + 1;
                    q.push(nn);
                }
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        array<int, 4> target;
        for (int i = 0; i < 4; ++i) {
            int x;
            cin >> x;
            x -= 1;
            target[i] = x;
        }

        sort(target.begin(), target.end());
        cout << dist[target[0]][target[1]][target[2]][target[3]] << el;
    }

    return 0;
}
