#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

void dfs(vector<int>& a, set<vector<int>>& vis, int& sum) {
    int currSum = accumulate(a.begin(), a.end(), 0);
    sum = max(sum, currSum);

    if (a.size() == 1 || vis.count(a)) return;
    
    vis.insert(a);
    
    vector<int> diff;
    for (int i = 0; i < (int)a.size() - 1; ++i) diff.push_back(a[i + 1] - a[i]);
    dfs(diff, vis, sum);
    
    reverse(a.begin(), a.end());
    diff.clear();
    for (int i = 0; i < (int)a.size() - 1; ++i) diff.push_back(a[i + 1] - a[i]);
    dfs(diff, vis, sum);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int sum = accumulate(a.begin(), a.end(), 0);
        set<vector<int>> vis;
        dfs(a, vis, sum);
        cout << sum << el;
    }

    return 0;
}
