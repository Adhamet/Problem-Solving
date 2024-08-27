#include <algorithm>
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

        vector<char> input(n + 1);

        int right_good = 0;
        for (int i = 1; i <= n; i++) {
            cin >> input[i];
            right_good += (input[i] == '1');
        }

        int pos = -1;
        int left_good = 0;

        for (int i = 0; i <= n; i++) {
            if (left_good * 2 >= i && right_good * 2 >= n - i && abs(i * 2 - n) < abs(pos * 2 - n)) {
                pos = i;
            }

            if (i < n) {
                if (input[i + 1] == '1') {
                    right_good--;
                } else {
                    left_good++;
                }
            }
        }

        cout << pos << '\n';
    }

    return 0;
}
