#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t

i64 mergeGo(vector<int> &vec, int tl, int tr) {
	if (tl >= tr) return 0;
	int tm = (tl + tr) >> 1;
	i64 inversions = mergeGo(vec, tl, tm) + mergeGo(vec, tm+1, tr);

	vector<int> tmp;
	int i = tl, j = tm + 1;
	while (i <= tm && j <= tr) {
		if (vec[i] <= vec[j]) tmp.push_back(vec[i++]);
		else {
			inversions += (tm - i + 1);
			tmp.push_back(vec[j++]);
		}
	}
	while (i <= tm) tmp.push_back(vec[i++]);
	while (j <= tr) tmp.push_back(vec[j++]);
	
	for (int k = tl; k <= tr; ++k) vec[k] = tmp[k - tl];
	return inversions;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i], a[i]--;

		i64 selfCuts = 0;
		vector<int> linesOf(n, 0);
		for (int i = 0; i < n; ++i) {
			selfCuts += linesOf[a[i]];
			linesOf[a[i]]++;
		}

		vector<int> b = a;
		i64 crossCuts = mergeGo(b, 0, n - 1);

		cout << selfCuts + crossCuts << '\n';
	}

	return 0;
}
