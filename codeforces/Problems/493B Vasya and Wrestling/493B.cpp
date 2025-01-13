#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, sum = 0;
    cin >> n;
    vector<int> f, s;

    bool last = false;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        sum += x;
        if (x > 0) f.push_back(x);
        else s.push_back(-x);
        if (i == n - 1 && x > 0) last = true;
    }

    if (sum > 0) cout << "first";
    else if (sum < 0) cout << "second";
    else {
        if (f > s) cout << "first";
        else if (s > f) cout << "second";
        else cout << (last ? "first" : "second");
    }
    return 0;
}
