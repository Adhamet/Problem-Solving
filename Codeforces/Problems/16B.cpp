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

    pair<ll, ll> arr[20];
    int n,m;	cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr+m, [](pair<ll,ll>& a, pair<ll,ll>& b) {
    	return a.second > b.second;
    });
	
	int sum = 0;
	for(int i = 0; i < m; i++) {
		if(n < arr[i].first) {
			sum += arr[i].second * n;
			break;
		}
		else {
			sum += arr[i].second * arr[i].first;
			n -= arr[i].first;
		}
	}
	cout << sum;
	
    return 0;
}