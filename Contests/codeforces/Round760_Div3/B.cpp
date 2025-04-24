#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        string finalRes, s;
        cin >> finalRes;
        for (int i = 1; i < n - 2; ++i) {
            cin >> s;
            if (finalRes.back() == s.front()) finalRes += s.back();
            else finalRes += s;
        }            

        if ((int)finalRes.size() != n) finalRes += finalRes.back();
        cout << finalRes << el;
    }

    return 0;
}