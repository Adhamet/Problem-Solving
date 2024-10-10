#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main() {
  adhamet;

  ll n;  cin >> n;
  ll a[n],b[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];

  vector<ll> coeffs;
  for(ll i = 0; i < n; i++) {
    coeffs.push_back( (i+1) * (n-i) * a[i] );
  }

  ll ans = 0;
  sort(coeffs.begin(), coeffs.end());
  sort(b, b+n, greater<int>());
  for(ll i = 0; i < n; i++) {
    ans += (coeffs[i] * b[i]);
  }
  cout << ans << el;
  
  return 0;
}
