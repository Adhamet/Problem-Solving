#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, array<int, 3>>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].second[0] >> arr[i].second[1] >> arr[i].second[2];
        arr[i].first = i;
    }

    int cnt = 0;
    vector<bool> ans(n, false);
    vector<array<int, 2>> cases = {{0, 1}, {0, 2}, {1, 2}};
    // (1, 2), (1, 3), (2, 3)
    for (int i = 0; i < 3; ++i) {
        sort(arr.begin(), arr.end(), [&](auto &a, auto &b) {
                return a.second[cases[i][0]] <= b.second[cases[i][0]] && a.second[cases[i][1]] <= b.second[cases[i][1]];
        });

        cout << "Case " << i + 1 << el;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 3; ++k) {
                cout << arr[j].second[k] << ' ';
            }
            cout << el;
        }
        
        for (int j = 0; j < n - 1; ++j) {
            if (arr[j].second[cases[i][0]] == arr[j + 1].second[cases[i][0]] && arr[j].second[cases[i][1]] == arr[j + 1].second[cases[i][1]]) {
                if (ans[arr[j].first] != true) {
                    ans[arr[j].first] = true;
                    cnt += 1;
                }
            } else if (arr[j].second[cases[i][0]] < arr[j + 1].second[cases[i][0]] && arr[j].second[cases[i][1]] < arr[j + 1].second[cases[i][1]]) {
                if (ans[arr[j].first] != true) {
                    cout << "HERE: ";
                    cout << arr[j].first + 1 << el;
                    ans[arr[j].first] = true;
                    cnt += 1;
                }

                break;
            }
        }
    }

    cout << cnt << el;
    for (int i = 0; i < n; ++i) {
        if (ans[i]) {
            cout << i + 1 << ' ';
        }
    }

    return 0;
}
