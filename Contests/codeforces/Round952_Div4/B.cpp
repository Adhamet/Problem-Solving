#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

/* void setIO(string name = "") { */
/*     if (name.size()) { */
/*         freopen((name+".in").c_str(), "r", stdin); */
/*         freopen((name+".out").c_str(), "w", stdout); */    
/*     } */
/* } */

int main()
{
    /* setIO("cowqueue"); */
    adhamet;

    int t;  cin >> t;
    while(t--) {
        int n;  cin >> n;

        int maxS = 0, bestX = 2;
        for(int x = 2; x <= n; x++) {
            int sum = 0, multiple = x;
            while(multiple <= n) {
                sum += multiple;
                multiple += x;
            }

            if(maxS < sum) {
                maxS = sum;
                bestX = x;
            }
        }

        cout << bestX << el;
    }

    return 0;
}
