#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    // redirectIO();
    adhamet;

    int n;    cin >> n;
    int a[2*n];
    for (int i = 0; i < (2*n); i++) cin >> a[i];
    
    sort(a,a+(2*n));
    int min_totalBal = INT_MAX;
    for(int i = 0; i < 2*n; i++) {
        for(int j = i+1; j < 2*n; j++) {
            vector<int> rem;
            for(int k=0; k<2*n; k++) if(k!=i && k!=j) rem.push_back(a[k]);
            
            int curr_totalBal = 0;
            for(int k=0; k<rem.size(); k+=2) curr_totalBal += abs(rem[k] - rem[k+1]);

            min_totalBal = min(min_totalBal, curr_totalBal);
        }
    }
    cout << min_totalBal;

    return 0;
}
