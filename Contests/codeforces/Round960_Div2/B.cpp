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
        int n, y, x;
        cin >> n >> y >> x;

        vector<int> vec(n + 1);
        for (int i = 1; i <= n; i++) vec[i] = 1;

        int numOnesPre = x;
        int numOnesSuff = y;

        int i = ceil(float(x) / 2);
        int j = ((n - y) / 2) + y;

        while (i <= x && numOnesPre >= (x - numOnesPre) * 2) {
            if (i >= j && i <= n && numOnesSuff >= (y - numOnesSuff) * 2) {
                numOnesPre--;
                numOnesSuff--;
                vec[i] = -1;
                j++;
            } else if (numOnesSuff < (y - numOnesSuff) * 2 && i < j) {
                numOnesPre--;
                vec[i] = -1;
            }

            i++;
        }

        while (j <= n && numOnesSuff >= (y - numOnesSuff * 2)) {
            if (j <= i && j <= n && numOnesPre >= (x - numOnesPre) * 2) {
                numOnesPre--;
                numOnesSuff--;
                vec[j] = -1;
                i++;
            } else if (numOnesPre < (y - numOnesPre) * 2 && j > i) {
                numOnesSuff--;
                vec[j] = -1;
            }

            j++;
        }

        for(int i = 1; i <= n; i++) cout << vec[i] << " ";
        cout << el;
    }

    return 0;
}
