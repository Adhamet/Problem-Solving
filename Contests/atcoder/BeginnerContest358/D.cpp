#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define vll vector<ll>
#define pLL pair<ll,ll>
#define F first
#define S second
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int n,m;    cin >> n >> m;
    vector<int> boxes(n), ppl(m);
    for(int i = 0; i < n; i++) cin >> boxes[i];
    for(int i = 0; i < m; i++) cin >> ppl[i];
    sort(boxes.begin(),boxes.end());
    sort(ppl.begin(),ppl.end());
    
    int minIdx = 1e9;
    for(int i = 0; i < m; i++) {
        if(boxes[i] >= ppl[0]) {
            minIdx = i;
            break;
        }
    }

    if(minIdx==1e9) return cout << -1, 0;

    ll ans = 0;
    int i = 0;
    for(; minIdx < n && i < m; minIdx++) {
        if(boxes[minIdx]>=ppl[i]) ans+=boxes[minIdx], i++;
    }

    if(i!=m) return cout << -1, 0; 
    cout << ans;

    return 0;
}
