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

int main()	{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), evens, odds;
        for (auto &i: a) cin >> i;
        sort(begin(a), end(a));

        for (auto i: a) {
            if (i % 2 == 0) evens.push_back(i);
            else odds.push_back(i);
        }

        if (evens.size() == n || odds.size() == n) {
            cout << 0 << el;
            continue;
        }

        int ans1 = evens.size() + 1, ans2 = 0;

        int oSZ = odds.size(), eSZ = evens.size(), lastE = 0;
        while (odds[oSZ - 1] < evens[eSZ - 1]) {
            int currentBestEven = 0;

            for (int i = lastE; i < eSZ; i++) {
                if (evens[i] > odds[oSZ - 1]) break;
                currentBestEven = evens[i];
            }
            
            if (currentBestEven == 0) {
                ans2 = 1e9;
                break;
            }

            odds.push_back(odds[oSZ - 1] + currentBestEven);
            oSZ += 1;

            evens.erase(find(begin(evens), end(evens), currentBestEven));
            eSZ -= 1;

            ans2 += 1;
        }

        cout << min(ans1, ans2 + eSZ) << el;
    }

    return 0;
}
