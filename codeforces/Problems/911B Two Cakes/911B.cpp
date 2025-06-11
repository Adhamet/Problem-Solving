#include <bits/stdc++.h>

using namespace std;
#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define lld long long double
#define ull unsigned long long
#define intPair pair<int,int>
#define llPair pair<ll,ll>
#define ldPair pair<lld,lld>
#define el '\n'

int main() 
{/* #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
#endif */
    adhamet

	ll n,a,b;
	cin >> n >> a >> b;
	if (a > b) swap(a,b);
	int l = 0, r = 100;
	while (l < r) {
		int mid = l + (r - l)/2;

		if (mid > a || n - ( (a-mid) / mid+1) > b / mid)
			r = mid - 1;
		else l = mid;
	}
	cout << l;

	return 0;
}
