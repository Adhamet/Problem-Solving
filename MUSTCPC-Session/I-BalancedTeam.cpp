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
    // freopen("file.in", "r", stdin);
    // freopen("file.out", "w", stdout);
	int n,k;	cin >> n >> k;
	int arr[n];

	for(int i = 0; i < n; i++) cin >> arr[i];

	ll tempAns = 0, ans=0, i=0, j=0;
	while(i <= j && j < n) {
		if (tempAns < k) {
			tempAns += arr[j];
			j++;
		}
		else {
			tempAns -= arr[i];
			i++;
		}
		if (tempAns <= k) ans = max(j-i,ans);
	}
	cout << ans << el;

    return 0;
}