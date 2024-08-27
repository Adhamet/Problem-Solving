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
        int n, m;
        cin >> n >> m;

        vector<int> vec(n);
        for (auto &i: vec) cin >> i;

        string s;
        cin >> s;

        int l = count(s.begin(), s.end(), 'L');
        int r = l;

        vector<int> ans(n);

        int num = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'L') num = num * vec[--l] % m;
            else num = num * vec[r++] % m;
           
            ans[i] = num;
        }

        for (int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << el;
    }

    return 0;
}
