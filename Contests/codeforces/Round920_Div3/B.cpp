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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int numOnes = 0, toChng = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && t[i] == '0') {
        numOnes += 1;
      } else if (s[i] == '0' && t[i] == '1') {
        if (numOnes > 0) {
          numOnes -= 1;
          ans += 1;
        } else toChng += 1;
      }
    }
    
    while (toChng > 0 && numOnes > 0) {
      toChng -= 1;
      numOnes -= 1;

      ans += 1;
    }

    ans += (toChng + numOnes);
    cout << ans << el;
  }

  return 0;
}
