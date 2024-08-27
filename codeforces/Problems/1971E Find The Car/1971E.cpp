#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t;
  cin >> t;

  while (t--) {
	  int n, k, q;
	  cin >> n >> k >> q;

	  vector<ll> a(k + 1), b(k + 1);
	  a[0] = b[0] = 0;

	  for (int i = 1; i <= k; i++) cin >> a[i];
	  for (int i = 1; i <= k; i++) cin >> b[i];

	  while (q--) {
		  ll d;
		  cin >> d;

		  int l = 0, r = k;
		  while (l <= r) {
			  int mid = l + (r - l) / 2;
			  if (a[mid] > d) {
				  r = mid - 1;
			  } else {
				  l = mid + 1;
			  }
		  }

		  if (a[r] == d) {
			  cout << b[r] << " ";
		  } else {
			  ll ans = b[r] + (d - a[r]) * (b[r + 1] - b[r]) / (a[r + 1] - a[r]);
			  cout << ans << " ";
		  }
	  }

	  cout << el;
  }

  return 0;
}
