#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        
        unordered_map<int, int> first, last, cnt;
        for (int i = 0; i < n; ++i) {
            if (!first.count(a[i])) first[a[i]] = i;
            last[a[i]] = i;
            cnt[a[i]]++;
        }
        
        int original_distinct = first.size();
        int best_gain = 0;
        int best_removed = 0;
        pair<int, int> best = {0, 0};
        
        // Check all possible elements
        for (auto& [x, _] : first) {
            int l = first[x];
            int r = last[x];
            int removed = r - l + 1;
            
            // Calculate union of left and right parts
            unordered_set<int> union_set;
            for (int i = 0; i < l; ++i) union_set.insert(a[i]);
            for (int i = r+1; i < n; ++i) union_set.insert(a[i]);
            
            int new_distinct = union_set.size();
            int gain = (original_distinct - new_distinct) - removed;
            
            // Update best if better gain or same gain with larger removal
            if (gain > best_gain || (gain == best_gain && removed > best_removed)) {
                best_gain = gain;
                best_removed = removed;
                best = {l+1, r+1};
            }
        }
        
        // Also check removing single elements (for minimal length when scores are equal)
        for (int i = 0; i < n; ++i) {
            int removed = 1;
            unordered_set<int> union_set;
            for (int j = 0; j < i; ++j) union_set.insert(a[j]);
            for (int j = i+1; j < n; ++j) union_set.insert(a[j]);
            
            int new_distinct = union_set.size();
            int gain = (original_distinct - new_distinct) - removed;
            
            if (gain > best_gain || (gain == best_gain && removed > best_removed)) {
                best_gain = gain;
                best_removed = removed;
                best = {i+1, i+1};
            }
        }
        
        // Decide output based on best gain
        if (best_gain > 0 || (best_gain == 0 && best_removed > 0)) {
            cout << best.first << " " << best.second << "\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}