#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define el '\n'

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> friends(m); 
        for (auto &vec: friends) {
            int sz;
            cin >> sz;
            vec.resize(sz);
            for (auto &ele: vec) cin >> ele;
        }

        bool acc = true;
        int mx = (m + 1) / 2;
        vector<int> cnt(n + 1), ans(m, -1);
        for (int i = 0; i < m; ++i) {
            if (friends[i].size() == 1) {
                int chosen = friends[i][0];

                ans[i] = chosen;
                cnt[chosen]++;

                if (cnt[chosen] > mx) {
                    acc = false;
                    break;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            if (ans[i] == -1) {
                bool assigned = false;
                
                for (int idx : friends[i]) {
                    if (cnt[idx] < mx) {
                        ans[i] = idx;
                        cnt[idx]++;
                        assigned = true;
                        break;
                    }
                }

                if (!assigned) {
                    acc = false;
                    break;
                }
            }
        }

        if (acc) {
            cout << "YES" << el;
            for (auto num: ans) cout << num << " ";
            cout << el;
        } else {
            cout << "NO" << el;
        }
    }

    return 0;
}
