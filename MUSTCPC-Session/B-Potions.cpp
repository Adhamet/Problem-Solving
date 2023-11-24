#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    int n, x;  cin >> n;
    ll sum = 0;

    while(n--) {
        cin >> x;
        pq.push(x);
        sum += x;
        while(sum < 0) {
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << pq.size();
    
    return 0;
}
