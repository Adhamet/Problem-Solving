#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
#define int long long
#define el '\n'

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

   int t;
   cin >> t;
   while (t--) {
    int n, k, p;
    cin >> n >> k >> p;
    if (n * p >= abs(k)) {
        cout << ceil(abs(k) / (double)p) << el;
    } else cout << -1 << el; 
   } 

    return 0;
}
