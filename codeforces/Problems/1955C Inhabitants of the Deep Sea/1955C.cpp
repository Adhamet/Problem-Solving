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
	  ll n, k;
	  cin >> n >> k;

	  deque<ll> dq(n);
	  for (int i = 0; i < n; i++) cin >> dq[i];

	  while (dq.size() > 1 && k) {
		  ll mn = min(dq.front(), dq.back());

		  if (k < 2 * mn) {
			  dq.front() -= (k / 2) + (k % 2);
			  dq.back() -= (k / 2);
			  k = 0;
		  } else {
			  dq.front() -= mn;
			  dq.back() -= mn;
			  k -= 2 * mn;
		  }

		  if (dq.front() == 0) dq.pop_front();
		  if (dq.back() == 0) dq.pop_back();
	  }

	  int ans = n - dq.size();
	  cout << ans + (dq.size() && dq.front() <= k) << el;
  }

  return 0;
}
