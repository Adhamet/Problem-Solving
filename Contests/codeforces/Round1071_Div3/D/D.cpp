#include <bits/stdc++.h>

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;
    int nn = std::pow(2,n);
    std::vector<bool> done(nn, false);
    std::vector<int> ans;

    int start = 0;
    int max_pop = -1;
    for (int i = 0; i < nn; i++) {
        int pop = __builtin_popcount(i);
        if (pop > max_pop || (pop == max_pop && i < start)) {
            max_pop = pop;
            start = i;
        }
    }

    ans.push_back(start);
    done[start] = true;
    int current = start;
    while (current > 0) {
        int next_num = -1;
        int best_target = -1;

        for (int bit = 0; bit < 20; bit++) {
            if (!(current & (1 << bit))) continue;

            int target = current ^ (1 << bit);
            for (int x = target; x < nn; x++) {
                if ((x & target) == target && !done[x]) {
                    if (next_num == -1 || x < next_num) {
                        next_num = x;
                        best_target = target;
                    }
                    break;
                }
            }
        }

        if (next_num == -1) break;

        ans.push_back(next_num);
        done[next_num] = true;
        current = best_target;

        for (int x = 0; x < nn; x++) {
            if (!done[x] && (x & current) == current) {
                ans.push_back(x);
                done[x] = true;
            }
        }
    }

    for (int i = 0; i < nn; i++) if (!done[i]) {
        ans.push_back(i);
    }

    for (int i = 0; i < (int)ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
