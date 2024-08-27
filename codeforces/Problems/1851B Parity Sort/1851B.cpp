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

        vector<int> vec(n);
        for (auto &i: vec) cin >> i;

        vector<int> sVec = vec;
        sort(sVec.begin(), sVec.end());

        bool acc = true;
        for (int i = 0; i < n; i++) if (sVec[i] % 2 != vec[i] % 2) acc = false;
        if (acc) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
