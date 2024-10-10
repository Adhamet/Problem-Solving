#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

// void setIO(string name = "") {
//     if (name.size()) {
//         freopen((name+".in").c_str(), "r", stdin);
//         freopen((name+".out").c_str(), "w", stdout);
//     }
// }

int main() {
  adhamet;

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];

  sort(arr.begin(), arr.end());
    
  int tuit = 0;
  long long maxM = 0;
  for (int i = 0; i < n; i++) {
    long long currM = 0;
    currM = (ll)arr[i] * (n - i);
    if(maxM < currM) {
        maxM = currM;
        tuit = arr[i];
    }
  }
  cout << maxM << " " << tuit;

  return 0;
}
