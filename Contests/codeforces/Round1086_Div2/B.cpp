#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    // sets of cards and a queue
    // from the sets of cards of which are playable use the minimum
    // making m -= minimum then put that minimum to the bottom
    // then put the one at top of queue into the set
    // and repeat,
    // WHENEVER I EVER GET THE CHANCE TO PLAY THE WINNING NUM
    // WE PLAY IT
    // a tracker for the winning num, if it is in the queue
    // for each queue played tracker--, until its inside my set
    // then it is back at the bottom of the queue meaning the end
    // so tracker = n
    // is it solvable by greedy? m is 5000 max so feasible
    // first case passes
    // second case passes
    // third case passes
    // fourth case passes

    int t;  std::cin >> t;
    while (t--) {
        // num of cards, num of cards playable at a time
        // initial pos of win, total energy
        int n, k, p, m;
        std::cin >> n >> k >> p >> m;
        p--;

        int val = 0;
        std::multiset<int> st;
        std::queue<int> q;
        for (int i = 0; i < n; i++) {
            int x;  std::cin >> x;
            if (i == p) val = x;
            if (i < k) st.insert(x);
            else q.push(x);
        }

        int ans = 0;
        int tracker = p;
        while (m > 0) {
            if (tracker < k) {
                if (val > m) break;
                ans++;
                m -= val;
                auto it = st.find(val);
                if (it != st.end()) st.erase(it);
                q.push(val);
                if (!q.empty()) {
                    st.insert(q.front());
                    q.pop();
                } else st.insert(val);
                tracker = n - 1;
            } else {
                if (*st.begin() > m) break;
                m -= *st.begin();
                int played = *st.begin();
                st.erase(st.begin());
                q.push(played);
                if (!q.empty()) {
                    st.insert(q.front());
                    q.pop();
                } else st.insert(played);
                tracker--;
            }
        }


        std::cout << ans << '\n';
    }

    return 0;
}
