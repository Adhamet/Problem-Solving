#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int n, m, k;
vector<vector<ll>> grid, pref;

ll calc(int i1, int j1, int i2, int j2) {
    if (i1 < 0) i1 = 0;
	if (i2 >= n) i2 = n - 1;
	if (j1 < 0) j1 = 0;
	if (j2 >= m) j2 = m - 1;
	
	ll answer = 0;
	answer += pref[i2][j2];
	if (i1 > 0) answer -= pref[i1 - 1][j2];
	if (j1 > 0) answer -= pref[i2][j1 - 1];
	if (i1 > 0 && j1 > 0) answer += pref[i1 - 1][j1 - 1];
	return answer;
}

bool works(int dist) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) continue;
            
            if (calc(i - dist, j - dist, i + dist, j + dist) >= k + 1) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> m >> k;
        
        // grid prepare & input taking
        grid.clear();
        ll totalCap = 0;
        for (int i = 0; i < n; i++) {
            vector<ll> row;
            
            for (int j = 0; j < m; j++) {
                ll element;
                cin >> element;
                
                totalCap += element;
                row.push_back(element);
            }
            
            grid.push_back(row);
        }
        
        if (totalCap < k + 1) {
            cout << -1 << el;
            continue;
        }
        // ---------------------
        
        // prefix prepare
        pref.clear();
        for (int i = 0; i < n; i++) pref.push_back(vector<ll>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pref[i][j] = grid[i][j];
                
                if (i > 0) pref[i][j] += pref[i - 1][j];
                if (j > 0) pref[i][j] += pref[i][j - 1];
                if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
            }
        }
        // --------------------
        
        
        // Binary Search on answer;
        int l = 0, r = max(n, m), ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            
            if (works(mid)) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        cout << ans << el;
    }

    return 0;
}
