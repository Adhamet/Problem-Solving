#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

// const int N = 20 + 5;
// const int oo = 1e9 + 20;

int solve(vector<int> cows, int x) {
    int wins = 0, mx = cows[0];

    for (int i = 1; i < cows.size(); i++) {
        mx = max(mx, cows[i]);
        if ( x == mx ) wins += 1;
    }

    return wins;
}

int main()	{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> cows(n);
        for (int i = 0; i < n; i++) cin >> cows[i];

        int me = cows[--k];

        swap(cows[0], cows[k]);
        int wins = solve(cows, me);
        swap(cows[0], cows[k]);

        for (int i = 0; i < n; i++) {
            if (cows[i] > me) {
                swap(cows[i], cows[k]);
                wins = max(wins, solve(cows, me));
                swap(cows[i], cows[k]);

                break;
            }
        }

        cout << wins << el;
    }

    return 0;
}
