#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;   cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<int> st;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (st.count(k - a[i])) {
            ans += 1;
            st.clear();
        } else {
            st.insert(a[i]);
        }
    }

    cout << ans;
}
