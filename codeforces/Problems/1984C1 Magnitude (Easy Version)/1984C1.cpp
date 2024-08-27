#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define ll long long
#define vll vector<ll>

int main() 
{
  int t;  cin >> t;
  
  while(t--) {
    ll n;  cin >> n;
    vll a(n);  for(ll i = 0; i < n; i++) cin >> a[i];
    ll mn = a[0], currPre=0, minPos=0;
    for(ll i = 0; i < n; i++) {
      currPre += a[i];
      if(currPre < mn) { minPos = i, mn = currPre; }
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++) {
      ans += a[i];
      if(i==minPos) ans = abs(ans);
    }
    cout << ans << el;
  }
  
  return 0;
}
