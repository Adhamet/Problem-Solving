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
	int n;	cin >> n;
	int weight[n];
	for(int i = 0; i < n; i++) cin >> weight[i];

	int pt1=0, pt2=n-1;
	ll sum1=0, sum2=0, ans=0;
	while( true ) {
		if ( pt1 > pt2 ) {
			if ( sum1 == sum2 )
				ans = max(ans,sum1);
			break;
		}

		if ( sum1 < sum2 ) sum1 += weight[pt1], pt1++;
		else if ( sum1 > sum2 ) sum2 += weight[pt2], pt2--;
		else ans = max(ans,sum1), sum1 += weight[pt1], pt1++;
	}
	cout << ans << el;
	
    return 0;
}