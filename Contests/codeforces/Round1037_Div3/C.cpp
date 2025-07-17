#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define el '\n'

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n, k;	cin >> n >> k;
		vector<i64> h(n+1);
		for (int i = 1; i <= n; i++) cin >> h[i];

		vector<pair<i64,int>> v;
		for (int i = 1; i <= n; i++) v.emplace_back(h[i], i);
		sort(v.begin(), v.end());

		vector<pair<i64,int>> u;
		i64 lstH = -1;
		for (auto &p: v) if (p.first != lstH) {
			u.push_back(p);
			lstH = p.first;
		}

		i64 strtH = h[k];
		int pos = -1;
		for (int i = 0; i < (int)u.size(); ++i) if (u[i].first == strtH) {
			pos = i;
			break;
		}

		i64 curT = 0, curH = strtH;
		bool acc = true;
		for(int i = pos + 1; i < (int)u.size(); i++){
			i64 nextH = u[i].first;
			i64 tel = llabs(curH - nextH);
			if(curT + tel > curH){
				acc = false;
				break;
			}

			curT  += tel;
			curH = nextH;
		}

		cout << (acc? "YES": "NO") << el;
	}

	return 0;
}

