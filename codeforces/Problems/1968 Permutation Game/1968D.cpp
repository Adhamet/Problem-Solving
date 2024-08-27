#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define el '\n'

ll score (vector<int>& p, vector<int>& a, int s, int k) {
	int n = p.size();
	ll mx = 0, curr = 0;
	vector<bool> vis(n);

	while (!vis[s] && k > 0) {
		vis[s] = 1;
		mx = max(mx, curr + (1LL * k * a[s]));
		curr += a[s];

		s = p[s];
		k--;
	}

	return mx;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t;
  cin >> t;

  while (t--) {
	  int n, k, pb, ps;
	  cin >> n >> k >> pb >> ps;

	  vector<int> p(n), a(n);
	  for (auto &i: p) {
		  cin >> i;
		  i--;
	  }

	  for (auto &i: a) cin >> i;

	  ll Bodya = score(p, a, pb - 1, k);
	  ll Sasha = score(p, a, ps - 1, k);

	  if (Bodya == Sasha) {
		  cout << "Draw" << el;
	  } else if (Bodya > Sasha) {
		  cout << "Bodya" << el;
	  } else {
		  cout << "Sasha" << el;
	  }
  }

  return 0;
}
