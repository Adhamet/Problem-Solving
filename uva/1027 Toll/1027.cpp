#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    const int oo = 1e18+5;
    int turn = 1;
    while (true) {
        int n, p;
        char a, b;
        if (!(cin >> n) || n < 0) break;

        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            g[a - 'A'].push_back(b - 'A');  
            g[b - 'A'].push_back(a - 'A');
        }

        cin >> p >> a >> b; 

        auto back = [](int hold, int node) {
            if (node > 26) return hold + 1;
            if (hold == 0) return 0;

            int l = hold + hold / 20;
            int i = hold;
            while (i) {
                if (i <= 0) continue;
                if (i - (i - 1) / 20 - 1 == hold) break;
            }

            return i;
        };

        pq.push({back(p, b - 'A'), b - 'A'});
        vis[b - 'A'] = true;

        while (!pq.empty()) {
            int d = pq.top().first, node = pq.top().second;
            pq.pop();

            if (vis[node]) continue;
            vis[node] = true;
            dist[node] = d;

            for (auto v : g[node]) {
                int d1 = min(dist[i], back(d, i));
                pq.push({d1, v});
            }
        }        

        for (int i: g[a - 'A']) { ans = min(ans, dist[i]); }

        if (a == b) cout << "Case " << turn << ": " << p << el;
        else cout << "Case " << turn << ": " << ans << el;
        turn++;
    }

    return 0;
}