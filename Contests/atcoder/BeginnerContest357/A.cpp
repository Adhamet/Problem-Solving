#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int n,M;
    cin >> n >> M;

    vector<int> H(n);
    for(int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    int count = 0;
    for(int i = 0; i < n; ++i) {
        if(M >= H[i]) {
            M -= H[i];
            count++;
        } else {
            break;
        }
    }

    cout << count << el;

    return 0;
}
