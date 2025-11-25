#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n), pos(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i; // 0-based
    }

    // Check if tree is possible
    int minPos = pos[1], maxPos = pos[1];
    bool valid = true;
    for (int i = 2; i <= n; ++i) {
        minPos = min(minPos, pos[i]);
        maxPos = max(maxPos, pos[i]);
        if (maxPos - minPos + 1 != i) valid = false; // if elements are not consecutive
    }

    if (!valid) {
        cout << "No\n";
        return;
    }

    // Compute next greater element indices
    vector<int> nge(n, -1);
    stack<int> stk;
    for (int i = n-1; i >= 0; --i) {
        while (!stk.empty() && p[stk.top()] <= p[i]) stk.pop();
        nge[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }

    cout << "Yes\n";
    for (int i = 1; i < n; ++i) {
        if (p[i] > p[0]) cout << p[0] << ' ' << p[i] << '\n';
        else if (nge[i] != -1) cout << p[nge[i]] << ' ' << p[i] << '\n';
        else cout << p[0] << ' ' << p[i] << '\n'; // fallback
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}

