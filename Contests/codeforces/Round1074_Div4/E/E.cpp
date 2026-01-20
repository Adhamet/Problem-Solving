#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int t;  std::cin >> t;
    while (t--) {
        int n, m, k;    std::cin >> n >> m >> k;
        std::vector<i64> robots(n), spikes(m);
        for (int i = 0; i < n; i++) std::cin >> robots[i];
        std::sort(robots.begin(), robots.end());
        for (int i = 0; i < m; i++) std::cin >> spikes[i];
        std::sort(spikes.begin(), spikes.end());

        std::string moves;  std::cin >> moves;
        std::vector<i64> pref(k + 1);   pref[0] = 0;

        std::unordered_map<i64, int> pos;
        for (int i = 1; i <= k; i++) {
            pref[i] = pref[i-1] + (moves[i-1]=='R'? 1: -1);
            if (pos.find(pref[i]) == pos.end()) {
                pos[pref[i]] = i;
            }
        }

        std::vector<int> deaths(k+2, 0);
        for (int i = 0; i < n; i++) {
            auto itR = std::lower_bound(spikes.begin(), spikes.end(), robots[i]);
            int curdead = k + 2;

            // check right spikes
            if (itR != spikes.end()) {
                auto curP = pos.find((*itR) - robots[i]);
                if (curP != pos.end()) {
                    curdead = std::min(curdead, curP->second);
                }
            }

            // check left spikes
            if (itR != spikes.begin()) {
                auto itL = itR; --itL;
                auto curP = pos.find((*itL) - robots[i]);
                if (curP != pos.end()) {
                    curdead = std::min(curdead, curP->second);
                }
            }

            if (curdead <= k) deaths[curdead] += 1;
        }

        int overallDeads=0;
        for (int i = 1; i <= k; i++) {
            overallDeads += deaths[i];
            std::cout << n -overallDeads << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
