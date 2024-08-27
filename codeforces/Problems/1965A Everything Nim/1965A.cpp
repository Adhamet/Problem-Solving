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
	  int n;
	  cin >> n;

	  set<int> piles;
	  int maxPile = 0;
	  for (int i = 0; i < n; i++) {
		  int x;
		  cin >> x;
		  piles.insert(x);
		  maxPile = max(maxPile, x);
	  }

	  int mex = 1;
	  for (auto pile: piles) {
		  if (mex == pile) mex += 1;
	  }

	  if (mex > maxPile) {
		  if (maxPile % 2 == 0) cout << "Bob\n";
		  else cout << "Alice\n";
	  } else {
		  if (mex % 2 == 0) cout << "Bob\n";
		  else cout << "Alice\n";
	  }
  }

  return 0;
}
