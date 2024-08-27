#include <bits/stdc++.h>
using namespace std;

bool can(int k, const vector<int>& vals) {
    int n = vals.size();
    vector<int> bits(21, 0);
    int curr_or = 0;

    // Calculate first OR
    for (int i = 0; i < k; i++) {
        curr_or |= vals[i];
        for (int j = 0; j < 21; j++) {
            if (vals[i] & (1 << j)) bits[j]++;
        }
    }

    int ref_or = curr_or;
    for (int i = 1; i <= n - k; i++) {
        int out = vals[i - 1];
        for (int j = 0; j < 21; j++) {
            if (out & (1 << j)) bits[j]--;
        }

        int in = vals[i + k - 1];
        curr_or = 0;
        for (int j = 0; j < 21; j++) {
            if (in & (1 << j)) bits[j]++;
            if (bits[j] > 0) curr_or |= (1 << j);
        }

        if (curr_or != ref_or) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vals(n);
        for (int i = 0; i < n; i++) cin >> vals[i];

        int l = 1, r = n, ans = n;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (can(mid, vals)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
