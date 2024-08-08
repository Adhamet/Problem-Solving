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
        int n, k;
        cin >> n >> k;

        vector<ll> vec(k);

        int maxEle = 0, maxIdx = 0;
        for (int i = 0; i < k; i++) {
            cin >> vec[i];
            
            if (maxEle < vec[i]) {
                maxEle = vec[i];
                maxIdx = i;
            }
        }

        ll numOps = 0, numOnes = 0;
        for (int i = 0; i < k; i++) if (i != maxIdx) {
            numOps += (vec[i] - 1);
            numOnes += vec[i];
        }

        cout << numOps + numOnes << el;
    }

    return 0;
}
