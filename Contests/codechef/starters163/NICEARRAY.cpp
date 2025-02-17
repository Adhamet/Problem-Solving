#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> vec(n);
        vector<int> floorVec(n), ceilVec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
            floorVec[i] = vec[i] / k;
            ceilVec[i] = (vec[i] > 0) ? (vec[i] + k - 1) / k : (vec[i] - k + 1) / k;
        }

        int floorSum = accumulate(floorVec.begin(), floorVec.end(), 0LL);
        int ceilSum = accumulate(ceilVec.begin(), ceilVec.end(), 0LL);
        if (floorSum == 0 || ceilSum == 0) cout << "YES" << el;
        else cout << "NO" << el;
    }

    return 0;
}
