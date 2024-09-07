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

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    cin >> n;

    vector<ll> cows(n);
    vector<ll> prefix(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
        prefix[i + 1] = (prefix[i] + cows[i]) % 7;
    }

    vector<int> lastFound(7);
    for (int i = 0; i < 7; i++) {
        lastFound[i] = -1;
    }

    int maximum = 0;

    for (int i = 0; i < prefix.size(); i++) {
        if (lastFound[prefix[i]] == -1) {
            lastFound[prefix[i]] = i;
        }
        else {
            maximum = max(i - lastFound[prefix[i]], maximum);
        }
    }

    cout << maximum << el;

    return 0;
}
