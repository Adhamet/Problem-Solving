#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define fst first
#define scd second
#define el '\n'
#define MOD 1000000007
 
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
 
const int MAXN = 1e6 + 4;
bool vis[MAXN];

void dfs(int node, vector<int>& adjL, int& cycle_size) {
    vis[node] = true;
    cycle_size++;
    if (!vis[adjL[node]]) {
        dfs(adjL[node], adjL, cycle_size);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            vis[i] = false;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                int cycle_size = 0;
                dfs(i, p, cycle_size);
				ans += (cycle_size - 1) / 2;
			}
        }

        cout << ans << el;
    }

    return 0;
}

