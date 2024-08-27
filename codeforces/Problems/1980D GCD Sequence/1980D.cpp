#include <bits/stdc++.h>
using namespace std;

#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define F first
#define S second
#define el '\n'

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

bool good(vector<int>& vec) {
    int GCD = __gcd(vec[0], vec[1]);

    for (int i = 1; i < int(vec.size()) - 1; i++) {
        int currGCD = __gcd(vec[i], vec[i+1]);
        if (GCD > currGCD) return false;
        GCD = currGCD;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        if (n == 1) {
            cout << "YES\n";
            continue;
        }

        int g = __gcd(arr[0], arr[1]);
        int toDel = -1;

        for (int i = 0; i < n - 1; i++) {
            int currGCD = __gcd(arr[i], arr[i + 1]);
            if (currGCD < g) {
                toDel = i;
                break;
            }
            g = currGCD;
        }

        if (toDel == -1) {
            cout << "YES\n";
            continue;
        }

        vector<int> ch1 = arr, ch2 = arr, ch3 = arr;

        if (toDel > 0) ch1.erase(ch1.begin() + toDel - 1);
        ch2.erase(ch2.begin() + toDel);
        if (toDel < n - 1) ch3.erase(ch3.begin() + toDel + 1);

        if (good(ch1) || good(ch2) || good(ch3)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

