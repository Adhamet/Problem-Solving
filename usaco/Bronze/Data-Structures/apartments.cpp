// CSES - 1084
#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int n,m,k;	cin >> n >> m >> k;
    int applicants[n],apartements[n];
	for (int i = 0; i < n; ++i) cin >> applicants[i];
	for (int i = 0; i < m; ++i) cin >> apartements[i];
	sort(applicants, applicants + n);
	sort(apartements, apartements + m);
	int i = 0, j = 0, ans = 0;
	while (i < n && j < m) {
		if (abs(applicants[i] - apartements[j]) <= k) {
			++i;
			++j;
			++ans;
		}
		else {
			if (applicants[i] - apartements[j] > k) ++j;
			else ++i;
		}
	}
    cout << ans;
}
