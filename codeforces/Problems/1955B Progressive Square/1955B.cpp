#include <bits/stdc++.h>
#include <climits>
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

bool solve() {
    int n, c, d;
    cin >> n >> c >> d;

    int sz = n * n;
    int arr[sz];

    map<int, int> mp;

    int a11 = INT_MAX;
    for(int i = 0; i < sz; i++) {
        cin >> arr[i];

        a11 = min(arr[i], a11);
        mp[arr[i]]++;
    }

    for (int i = a11; i < a11+n*c; i+=c) {
        if (mp[i]) {
            mp[i]--;

            for (int j = i + d; j < i+n*d; j+=d) {
                if (mp[j]) mp[j]--;
                else return 0;
            }
        } else return 0;
    }

    return 1;
}

int main()	{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
